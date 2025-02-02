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
#ifndef __INDEXLIB_INDEX_PARTITION_OPTIONS_H
#define __INDEXLIB_INDEX_PARTITION_OPTIONS_H

#include <memory>

#include "indexlib/common_define.h"
#include "indexlib/config/offline_config.h"
#include "indexlib/config/online_config.h"
#include "indexlib/indexlib.h"

DECLARE_REFERENCE_CLASS(config, IndexPartitionSchema);
DECLARE_REFERENCE_CLASS(config, IndexPartitionOptionsImpl);
DECLARE_REFERENCE_CLASS(config, UpdateableSchemaStandards);

namespace indexlib { namespace config {

class IndexPartitionOptions : public autil::legacy::Jsonizable
{
public:
    IndexPartitionOptions();
    IndexPartitionOptions(const IndexPartitionOptions& options);
    ~IndexPartitionOptions();

public:
    void SetOnlineConfig(const OnlineConfig& onlineConfig);
    void SetOfflineConfig(const OfflineConfig& offlineConfig);
    const OnlineConfig& GetOnlineConfig() const;
    const OfflineConfig& GetOfflineConfig() const;
    OnlineConfig& GetOnlineConfig();
    OfflineConfig& GetOfflineConfig();
    void SetIsOnline(bool isOnline);
    bool IsOnline() const;
    bool IsOffline() const;
    bool NeedLoadIndex() const;
    const BuildConfig& GetBuildConfig(bool isOnline) const;
    BuildConfig& GetBuildConfig(bool isOnline);
    const BuildConfig& GetBuildConfig() const;
    BuildConfig& GetBuildConfig();
    const MergeConfig& GetMergeConfig() const;
    MergeConfig& GetMergeConfig();
    // for legacy index_format_version
    void SetEnablePackageFile(bool enablePackageFile = true);
    void RewriteForSchema(const IndexPartitionSchemaPtr& schema);
    void SetReservedVersions(const std::set<versionid_t>& versionSet);
    const std::set<versionid_t>& GetReservedVersions() const;

    void SetOngoingModifyOperationIds(const std::vector<schema_opid_t>& ids);
    const std::vector<schema_opid_t>& GetOngoingModifyOperationIds() const;

    bool NeedRewriteFieldType() const;
    void SetNeedRewriteFieldType(bool need);

    void AddVersionDesc(const std::string& key, const std::string& value);
    void DelVersionDesc(const std::string& key);
    bool GetVersionDesc(const std::string& key, std::string& value) const;
    const std::map<std::string, std::string>& GetVersionDescriptions() const;

    void SetUpdateableSchemaStandards(const UpdateableSchemaStandards& standards);
    const UpdateableSchemaStandards& GetUpdateableSchemaStandards() const;

public:
    void Jsonize(autil::legacy::Jsonizable::JsonWrapper& json) override;
    void Check() const;
    void RewriteBuildConfig(TableType tableType, BuildConfig& buildConfig);
    void operator=(const IndexPartitionOptions& options);

private:
    IndexPartitionOptionsImplPtr mImpl;

public:
    bool TEST_mReadOnly;

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(IndexPartitionOptions);
}} // namespace indexlib::config

#endif //__INDEXLIB_INDEX_PARTITION_OPTIONS_H
