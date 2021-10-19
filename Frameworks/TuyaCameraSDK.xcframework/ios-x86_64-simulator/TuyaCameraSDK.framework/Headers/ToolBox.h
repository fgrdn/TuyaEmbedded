//
//  ToolBox.h
//  Tuya
//
//  Created by PaperMan on 18/3/5.
//  Copyright (c) 2018年 Tuya. All rights reserved.
//

#ifndef __TOOL_BOX_H__
#define __TOOL_BOX_H__

#import <Foundation/Foundation.h>

@interface ToolBox : NSObject{
    
}

+ (void)write2File:(char *)pFileName data:(unsigned char *)pByData length:(int)nLength;

@end

#endif  // __TOOL_BOX_H__
