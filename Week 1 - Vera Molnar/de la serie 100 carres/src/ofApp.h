#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();

        void keyReleased(int key);
        
        int seed = 0;
        ofImage image = ofImage("img.png");
        int imageIndex = 0;
    
};
