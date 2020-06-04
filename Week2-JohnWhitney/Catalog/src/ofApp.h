#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
    
    ofPath path;
    int mode = 2;
};
