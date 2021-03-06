#pragma once

#include "pid/ec/pid.hpp"

#include <phosphor-logging/log.hpp>
#include <sdbusplus/bus.hpp>

#include <limits>
#include <string>

namespace pid_control
{

void tryRestartControlLoops(void);

/*
 * Given a configuration structure, fill out the information we use within the
 * PID loop.
 */
void initializePIDStruct(ec::pid_info_t* info, const ec::pidinfo& initial);

void dumpPIDStruct(ec::pid_info_t* info);

struct SensorThresholds
{
    double lowerThreshold = std::numeric_limits<double>::quiet_NaN();
    double upperThreshold = std::numeric_limits<double>::quiet_NaN();
};

const std::string sensorintf = "xyz.openbmc_project.Sensor.Value";
const std::string criticalThreshInf =
    "xyz.openbmc_project.Sensor.Threshold.Critical";
const std::string propertiesintf = "org.freedesktop.DBus.Properties";

/*
 * Given a path that optionally has a glob portion, fill it out.
 */
std::string FixupPath(std::string original);

} // namespace pid_control
