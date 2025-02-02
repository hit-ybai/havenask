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
#ifndef __INDEXLIB_ATTRIBUTE_CONFIG_CREATOR_H
#define __INDEXLIB_ATTRIBUTE_CONFIG_CREATOR_H

#include <memory>

#include "indexlib/common_define.h"
#include "indexlib/config/FileCompressSchema.h"
#include "indexlib/config/attribute_config.h"
#include "indexlib/config/field_schema.h"
#include "indexlib/config/index_config.h"

namespace indexlib { namespace config {

class AttributeConfigCreator
{
public:
    AttributeConfigCreator();
    ~AttributeConfigCreator();

    AttributeConfigCreator(const AttributeConfigCreator&) = delete;
    AttributeConfigCreator& operator=(const AttributeConfigCreator&) = delete;
    AttributeConfigCreator(AttributeConfigCreator&&) = delete;
    AttributeConfigCreator& operator=(AttributeConfigCreator&&) = delete;

public:
    static AttributeConfigPtr Create(const FieldSchemaPtr& fieldSchema,
                                     const std::shared_ptr<FileCompressSchema>& fileCompressSchema,
                                     const autil::legacy::Any& attrConfigJson);

    static AttributeConfigPtr Create(const FieldSchemaPtr& fieldSchema, const std::string& fieldName,
                                     const CustomizedConfigVector& customizedConfigs = CustomizedConfigVector());

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(AttributeConfigCreator);
}} // namespace indexlib::config

#endif //__INDEXLIB_ATTRIBUTE_CONFIG_CREATOR_H
