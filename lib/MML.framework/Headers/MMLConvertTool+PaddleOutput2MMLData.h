//
//  MMLConvertTool+PaddleOutput2MMLData.h
//  MML
//
//  Created by Wang,Zhiyong on 2019/11/27.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MMLSDK/MMLSDK.h>
#import "MMLConvertTool.h"
#import "MMLData.h"

NS_ASSUME_NONNULL_BEGIN
/**
 * MMLConvertTool  paddle cpu & gpu output >> MMLData
*/
@interface MMLConvertTool(PaddleOutput2MMLData)
#if __has_include("PaddleMobileCPU.h")
/**
 paddle cpu output >> MMLData

 @param outputData 输入的Paddle CPU output
 @return 转换后的MMLData
*/
+ (MMLData *)convertPaddleCPUOutputToMMLOutput:(MMLPaddlePredicateOutputs *)outputData;
#endif
/**
 paddle gpu output >> MMLData

 @param outputData 输入的Paddle GPU output
 @return 转换后的MMLData
*/
+ (MMLData *)convertPaddleGPUOutputToMMLOutput:(PaddleMobileGPUResult *)outputData ;

@end

NS_ASSUME_NONNULL_END
