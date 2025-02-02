/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __INDEXLIB_HASH_TABLE_OPTIONS_H
#define __INDEXLIB_HASH_TABLE_OPTIONS_H

#include <limits>

#include "indexlib/common_define.h"

namespace indexlib { namespace common {

static const int32_t INVALID_OCCUPANCY = std::numeric_limits<int32_t>::min();

struct HashTableOptions {
    HashTableOptions(int32_t _occupancyPct) : occupancyPct(_occupancyPct), mayStretch(false), maxNumHashFunc(8) {}
    int32_t occupancyPct;
    bool mayStretch;
    // cuckoo
    uint8_t maxNumHashFunc;

    bool Valid() const { return occupancyPct != INVALID_OCCUPANCY; }
};
}} // namespace indexlib::common

#endif //__INDEXLIB_HASH_TABLE_OPTIONS_H
