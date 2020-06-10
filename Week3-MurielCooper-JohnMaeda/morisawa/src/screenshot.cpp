//
//  screenshot.cpp
//  00_utils_screenshot
//
//  Created by Lisa Jamhoury on 6/7/20.
//

#include "screenshot.hpp"

screenshotUtil::screenshotUtil() {
    imageTaken = false;
}

void screenshotUtil::run() {
    
    // take screenshot on first frame only
    if (!imageTaken) {
        take();
        imageTaken = true;
    }
    
}


void screenshotUtil::take() {
    ofImage image;
    image.grabScreen(0,0,ofGetWidth(),ofGetHeight());
    string str = "images/devImgs/devImg";
    str += ofToString(ofGetTimestampString()) + ".jpg";
    image.saveImage(str);
    std::cout << "screenshot taken" << endl;
}
