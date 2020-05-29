#pragma once

#include "ofMain.h"
#include <math.h>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
        
    ofPolyline trail[8];
};
