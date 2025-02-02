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
#include "indexlib/table/normal_table/SegmentSortDecisionMaker.h"

#include "indexlib/framework/Segment.h"

namespace indexlibv2::table {

SegmentSortDecisionMaker::SegmentSortDecisionMaker() {}

SegmentSortDecisionMaker::~SegmentSortDecisionMaker() {}

bool SegmentSortDecisionMaker::NeedSortMemSegment(const config::SortDescriptions& sortDescriptions,
                                                  segmentid_t segmentId)
{
    if (sortDescriptions.empty() || framework::Segment::IsPrivateSegmentId(segmentId)) {
        return false;
    }
    return true;
}
bool SegmentSortDecisionMaker::IsSortedDiskSegment(const config::SortDescriptions& sortDescriptions,
                                                   segmentid_t segmentId)
{
    return NeedSortMemSegment(sortDescriptions, segmentId);
}

} // namespace indexlibv2::table
