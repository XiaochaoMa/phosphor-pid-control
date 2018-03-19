/**
 * Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <chrono>
#include <fstream>
#include <iostream>

#include "sysfs/sysfsread.hpp"


ReadReturn SysFsRead::read(void)
{
    int64_t value;
    std::ifstream ifs;

    ifs.open(_path);
    ifs >> value;
    ifs.close();

    struct ReadReturn r = {
        static_cast<double>(value),
        std::chrono::high_resolution_clock::now()
    };

    return r;
}