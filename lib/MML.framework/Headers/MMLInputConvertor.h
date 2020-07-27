//
//  MMLInputConvertor.h
//  MML
//
//  Created by QingCan on 2019/11/18.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMLMachineConfig.h"
#import "MMLData.h"

#import <MMLSDK/MMLInputMatrix.h>
#import <MMLSDK/MMLSDK.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *MMLInputConvertor
 */
@interface MMLInputConvertor : NSObject

/**
  MMLData转换PaddleInput
 
  @param inputData 输入数据
  @return MMLInputMatrix返回的paddle input matrix
 */
+ (MMLInputMatrix *)convertMMLInputToPaddleInput:(MMLData *)inputData;

/**
  MMLData转换BMLinput
 
  @param inputData 输入数据
  @return MMLInputData返回的BML input data
 */
+ (MMLInputData *)convertMMLInputToMachineLearningInput:(MMLData *)inputData;

@end

NS_ASSUME_NONNULL_END
