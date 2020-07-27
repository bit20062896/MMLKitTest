//
//  MMLPaddleConfig.h
//  MML
//
//  Created by QingCan on 2019/11/19.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MMLSDK/MMLSDK.h>
#import "MMLInferenceEngineConfigProtocol.h"
#if __has_include("PaddleMobileCPU.h")
#import "PaddleMobileCPU.h"
#endif
NS_ASSUME_NONNULL_BEGIN
/// Paddle Machine的配置
@interface MMLPaddleConfig : NSObject <MMLInferenceEngineConfigProtocol>
/// machineType == MMLPaddleCPU时，必须配置CPU Inference Engine的配置，此时参数必选
#if __has_include("PaddleMobileCPU.h")
@property (nonatomic, strong) PaddleMobileCPUConfig *paddleCPUConfig;
#endif
/// machineType == MMLPaddleGPU时，可以配置GPU Inference Engine的配置，此时参数可选
@property (nonatomic, strong) ModelConfig *paddleGPUConfig;
/// machineType == MMLPaddleGPU时，必须配置GPU Inference Engine的net类型，此时参数必选
@property (nonatomic, assign) NetType netType;

/// ！！之所以需要解密的模型内存指针单独拎出来，是因为Paddle的CPUConfig中不支持配置模型内存指针，而Paddle的GPUConfig内是可以直接配置内存指针的，因此拎出来是为了向下兼容

/// fluid模型内存指针
@property (nonatomic, assign) unsigned char * modelPointer;
/// fluid参数内存指针
@property (nonatomic, assign) unsigned char * paramPointer;
/// 模型内存大小
@property (nonatomic, assign) size_t modelSize;
/// 参数内存大小
@property (nonatomic, assign) size_t paramSize;
@end

NS_ASSUME_NONNULL_END
