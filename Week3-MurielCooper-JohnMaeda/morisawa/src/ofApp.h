#pragma once

#include "ofMain.h"
#include "screenshot.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();

		
        ofTrueTypeFont font;
          screenshotUtil screenshot;
};
