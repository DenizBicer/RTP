#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void draw();
    ofxFloatSlider a, b, d;
    ofxPanel gui;
    
    ofPolyline trail[64];

};
