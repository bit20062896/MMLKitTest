//
//  MMLConvertTool+MMLData2MachineLearningInput.h
//  MML
//
//  Created by Wang,Zhiyong on 2019/11/27.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMLConvertTool.h"
NS_ASSUME_NONNULL_BEGIN

/**
 * 转换工具 MMLData >> BML input
*/
@interface MMLConvertTool(MMLData2MachineLearningInput)

/**
 mmlTensor -> BML input

 @param mmlTensor 输入的MMLTensor数据
 @return 转换后的MMLInputData
*/
+ (MMLInputData *)mlInputDataConvertFromMMLTensor:(MMLBMLTensor *)mmlTensor;

@end

NS_ASSUME_NONNULL_END
