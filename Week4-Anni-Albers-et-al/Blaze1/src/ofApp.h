#pragma once

#include "ofMain.h"
#include "Circle.h"


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyReleased(int key);
    vector < ofPoint > GenerateArrow(Circle a, Circle b, float sample, float thickness);
    
    string appname;
    
    Circle circles[7];
    int sizes[7];
    int circleCount = 7;
    
    float sampleDegree = -8;
    vector<ofPolyline> lines;
};
