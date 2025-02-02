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
#include "indexlib/index/common/numeric_compress/VbyteInt32Encoder.h"

#include "indexlib/index/common/numeric_compress/VbyteCompressor.h"

namespace indexlib::index {
namespace {
}

AUTIL_LOG_SETUP(indexlib.index, VbyteInt32Encoder);

VbyteInt32Encoder::VbyteInt32Encoder() {}

VbyteInt32Encoder::~VbyteInt32Encoder() {}

std::pair<Status, uint32_t> VbyteInt32Encoder::Encode(file_system::ByteSliceWriter& sliceWriter, const uint32_t* src,
                                                      uint32_t srcLen) const
{
    // src len using uint8_t.because of MAX_RECORD_SIZE is 128
    uint32_t len = 1;
    sliceWriter.WriteByte((uint8_t)srcLen);
    for (uint32_t i = 0; i < srcLen; ++i) {
        len += sliceWriter.WriteVInt(src[i]);
    }
    return std::make_pair(Status::OK(), len);
}

std::pair<Status, uint32_t> VbyteInt32Encoder::Encode(uint8_t* dest, const uint32_t* src, uint32_t srcLen) const
{
    dest[0] = (uint8_t)srcLen;
    uint32_t destLen = 0;
    for (uint32_t i = 0; i < srcLen; ++i) {
        auto [status, len] = VByteCompressor::EncodeVInt32(dest + destLen, -1, src[i]);
        RETURN2_IF_STATUS_ERROR(status, 0, "encode vint32 fail");
        destLen += len;
    }
    return std::make_pair(Status::OK(), destLen);
}

std::pair<Status, uint32_t> VbyteInt32Encoder::Decode(uint32_t* dest, uint32_t destLen,
                                                      file_system::ByteSliceReader& sliceReader) const
{
    uint32_t len = (uint32_t)sliceReader.ReadByte();
    for (uint32_t i = 0; i < len; ++i) {
        dest[i] = sliceReader.ReadVInt32();
    }
    return std::make_pair(Status::OK(), len);
}
} // namespace indexlib::index
