#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(251);
    ofSetColor(44);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float stepSize = 15;
    float margin = 20 + stepSize*0.5;
    float squareSize = ofMap(mouseX, 0, 400, 8, 16);
//    float squareSize = 15;
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for(int i=0; i< 24; ++i)
    {
        for(int j=0; j< 24; ++j)
        {
            ofPushMatrix();
            float x = margin + i*stepSize;
            float y = margin + j*stepSize;
            ofTranslate(x, y);
            float n = ofNoise(x*0.05, y*0.05);
           if(n>ofMap(mouseY, 0, 400, 0, 1))
//            if(n>0.4)
            ofRotateDeg(45);
            ofDrawRectangle(0, 0, squareSize, squareSize);
            ofPopMatrix();
            
        }
    }
}

