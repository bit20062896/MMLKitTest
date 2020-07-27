//
//  MMLOutputConvertor.h
//  MML
//
//  Created by QingCan on 2019/11/18.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MMLSDK/MMLSDK.h>
#import "MMLMachineConfig.h"
#import "MMLData.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 预测output数据转换MMLData
 */
@interface MMLOutputConvertor : NSObject
#if __has_include("PaddleMobileCPU.h")
/**
  PaddleCPUOutput转换MMLData
 
  @param outputData 输入数据
  @return MMLData 返回的MMLData
 */
+ (MMLData *)convertPaddleCPUOutputToMMLOutput:(id)outputData;
#endif
/**
  PaddleGPUOutput转换MMLData
 
  @param outputData 输入数据
  @return MMLData 返回的MMLData
 */
+ (MMLData *)convertPaddleGPUOutputToMMLOutput:(id)outputData;

/**
  BML output转换MMLData
 
  @param outputData 输入数据
  @return MMLData 返回的MMLData
 */
+ (MMLData *)convertMachineLearningOutputToMMLOutput:(MMLOutputData *)outputData;

+ (NSArray<MMLData *> *)convertPaddleGPUOutputsToMMLOutputs:(NSArray *)outputDatas;

@end

NS_ASSUME_NONNULL_END
