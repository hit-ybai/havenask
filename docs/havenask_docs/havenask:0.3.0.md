# 版本概述
## 概述
* 支持Havenask分布式部署能力，详见[hape介绍](https://github.com/alibaba/havenask/wiki/Havenask%E5%88%86%E5%B8%83%E5%BC%8F%E8%BF%90%E7%BB%B4%E5%B7%A5%E5%85%B7)
* 支持实时数据更新
    * [实时写入example](https://github.com/alibaba/havenask/wiki/%E5%AE%9E%E6%97%B6%E5%8A%9F%E8%83%BD%E4%BD%BF%E7%94%A8%E6%96%87%E6%A1%A3)
    * [hape工具下的实时写入场景](https://github.com/alibaba/havenask/wiki/Hape%E5%B8%B8%E8%A7%81%E8%BF%90%E7%BB%B4%E5%9C%BA%E6%99%AF)
* 新增function插件、summary插件、bs processor插件、bs reader插件的[示例和文档](https://github.com/alibaba/havenask/tree/v0.3.0/aios/plugin_platform)
## 代码分支
* [v0.3.0](https://github.com/alibaba/havenask/tree/v0.3.0)
## 镜像版本
### 开发镜像
```
docker hub: havenask/ha3_dev:0.3.0
阿里云镜像: registry.cn-hangzhou.aliyuncs.com/havenask/ha3_dev:0.3.0
```
### 运行镜像
```
docker hub: havenask/ha3_runtime:0.3.0
阿里云镜像: registry.cn-hangzhou.aliyuncs.com/havenask/ha3_runtime:0.3.0
```
# 功能变化列表
|  功能  | 状态 |
|  ----  | ----  |
| 实时数据更新 | 新增 |
| 分布式集群部署  | 新增 |
|多插件示例|新增|
# bug fix列表
* [MultiPartitionMerger的counter merge不准确](https://github.com/alibaba/havenask/issues/31)
# 兼容性说明
## 配置兼容性
兼容以前版本的配置。
## 索引兼容性
兼容以前版本的索引。
## 性能变化
性能无变化。