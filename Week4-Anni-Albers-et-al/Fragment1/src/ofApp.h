#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void draw();
    void keyReleased(int key);
    vector < ofPoint > CreateArrow(ofPolyline top,ofPolyline mid, ofPolyline bottom, float percentage );
    
    string appname;
    
    
};
