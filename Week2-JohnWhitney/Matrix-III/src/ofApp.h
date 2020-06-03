#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void draw();
    float getScale(int seed);
    float getPhase(int seed);
    float getVariety(int seed);
    float getCenterOffset();
    
    float t = 0;
    bool goToCenter = false;
    float centerStartTime;
    
    float centerLapseDuration =30;
};
