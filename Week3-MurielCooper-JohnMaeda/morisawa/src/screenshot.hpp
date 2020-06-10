//
//  screenshot.hpp
//  00_utils_screenshot
//
//  Created by Lisa Jamhoury on 6/7/20.
//

#ifndef screenshot_hpp
#define screenshot_hpp

#include <stdio.h>
#include "ofMain.h"

class screenshotUtil {
    
public:
    
    void run();
    void take();
    
    screenshotUtil();
    
private:
    
    bool imageTaken;

    
};



#endif /* screenshot_hpp */
