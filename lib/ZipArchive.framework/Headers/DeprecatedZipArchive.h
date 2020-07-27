//
//  ZipArchive.h
//  ZipArchive
//
//  Created by Serhii Mumriak on 12/1/15.
//  Copyright © 2015 smumryak. All rights reserved.
//

/**
 * 废弃的类，只作为 糯米 的兼容，禁止引用
 * 详情见 readme
 */

#ifdef __OBJC__
#import <Foundation/Foundation.h>
#import <ZipArchive/SSZipArchive.h>
#endif

@protocol ZipArchiveDelegate <NSObject>
@optional

-(void) ErrorMessage:(NSString*) msg;

@end

@interface ZipArchive : NSObject

@property (nonatomic, retain) id<ZipArchiveDelegate> delegate;
@property (nonatomic, readonly) NSArray *unzippedFiles;
@property (nonatomic, copy) NSString *zipPath;

/**
 * @deprecated use SSZipArchive instead
 */
-(BOOL) UnzipOpenFile:(NSString*) zipFile __attribute__ ((deprecated));

/**
 * @deprecated use SSZipArchive instead
 */
-(BOOL) UnzipFileTo:(NSString*) path overWrite:(BOOL) overwrite __attribute__ ((deprecated));

/**
 * @deprecated use SSZipArchive instead
 */
-(NSDictionary *)UnzipFileToMemory __attribute__ ((deprecated));

/**
 * @deprecated use SSZipArchive instead
 */
-(BOOL) UnzipCloseFile __attribute__ ((deprecated));

@end
