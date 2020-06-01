#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(244, 244, 236);
    ofSetColor(77, 71, 124);
    ofSetLineWidth(2);
    
    float lineLength = 8;
    
    float angle = 22.5;
    for(int i=0; i<8; i++)
    {
        ofVec2f p1, p2;
        p1.set(-lineLength, 0);
        p2.set(lineLength, 0);
        
        p1.rotate(angle*i);
        p2.rotate(angle*i);
        
        map[i][0]= p1;
        map[i][1]= p2;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float stepSize = 15;
    float margin = 20 +stepSize/2;
    float lineLength = 8;
    
    ofSeedRandom(2);
    

    for(int i=0; i< 51; i++)
    {
        for(int j=0; j<51; j++)
        {
            float x = margin + i*stepSize;
            float y = margin + j*stepSize;
            
            float r = ofRandom(10);
        
            if(r>=8)
            {
                continue;
            }
            int rotationIndex = floorf(r);
            
            ofDrawLine(x+ map[rotationIndex][0].x, y+ map[rotationIndex][0].y,  x+map[rotationIndex][1].x, y+map[rotationIndex][1].y);
        }
    }
}

