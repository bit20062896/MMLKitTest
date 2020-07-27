//
//  MMLConvertTool.h
//  MML
//
//  Created by Wang,Zhiyong on 2019/11/21.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMLData.h"
#import <MMLSDK/MMLInputMatrix.h>
#import <MMLSDK/MMLSDK.h>
#import "MMLMachineConfig.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * MMLConvertTool MMLdata <--> Machine input\Machine output转换工具
*/
@interface MMLConvertTool : NSObject

#pragma mark input

/**
 MMLData -> MMLInputMatrix转换

 @param inputData 输入的MMLData
 @return 转换后的MMLInputMatrix
*/
+ (MMLInputMatrix *)convertMMLInputToPaddleInput:(MMLData *)inputData;

/**
 inputData -> MMLInputData转换

 @param inputData 输入的MMLData
 @return 转换后的MMLInputData
*/
+ (MMLInputData *)convertMMLInputToMachineLearningInput:(MMLData *)inputData;

@end

NS_ASSUME_NONNULL_END
