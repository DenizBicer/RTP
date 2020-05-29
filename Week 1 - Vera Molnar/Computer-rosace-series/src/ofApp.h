#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void drawSquareOne(float centerX, float centerY, float size, float variation);
        void drawSquareTwo(float centerX, float centerY, float distance, float variation, int index);
        void drawSquareThree(float centerX, float centerY, float distance, float variation, int index);
        void drawSquareFour(float centerX, float centerY, float distance, float variation, int index);


       ofxFloatSlider minGray, maxGray, noiseRate, distance, stepCount, cornerOffset, seed;
        ofxPanel gui;
};
