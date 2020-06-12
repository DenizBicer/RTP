#pragma once

#include "ofMain.h"
#include "Circle.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
        void update();
		void draw();
        
        void keyReleased(int key);
        vector < ofPoint > GenerateArrow(Circle a, Circle b, int sample, float thickness);

        string appname;
        
        Circle circles[6];
        int sizes[6];
    
        float sampleDegree = -8;
    vector<ofPolyline> lines;
};
