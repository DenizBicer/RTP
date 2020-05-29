#include "ofApp.h"
enum Mode {
      sketch,
      game
      };
  
  Mode mode = sketch;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(215, 219, 211);
    ofSetColor(0);
}


//--------------------------------------------------------------
void ofApp::draw(){
    float stepSize = 36;
    float margin = 20 + stepSize*0.5;
    float squareSize = 34;
    
    ofSeedRandom(this->seed);
        
    float displacementX = 2;
    float displacementY = 5;
    
    if(mode == game)
    {
        stepSize = 16;
        margin = 0 + stepSize*0.5;
        squareSize = 15;
          
        float hX = ofRandom(400);
        float hY = ofRandom(400);
            
        displacementX = mouseX - hX;
        displacementY = mouseY - hY;
    }
    
    ofSetColor(0);
    int gridSize = mode == sketch ? 10 : 25;
    
    for(int i=0; i<gridSize; i++)
    {
        for(int j=0; j<gridSize; j++)
        {
            float x = margin + i*stepSize;
            float y = margin + j*stepSize;
           
            if(mode == game)
                ofSetColor(image.getColor(floorf(x), floorf(y)));
            
            float noise =ofSignedNoise(x, y);
            float noiseY = noise * displacementY;
            float noiseX = noise * displacementX;
            ofDrawRectangle(x + noiseX, y + noiseY, squareSize, squareSize);
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == ' '){
        this->seed = ofRandom(100);
        imageIndex++;
        imageIndex %=2;
        if(imageIndex == 0)
            image = ofImage("img.png");
        else
            image = ofImage("img2.png");
    }
    
    if(key == 'm'){
        mode = static_cast<Mode> ((mode+1)%2);
    }
}
