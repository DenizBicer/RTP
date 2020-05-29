#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    float time =ofGetElapsedTimef();
    float period = ofGetHeight();
    
    for(int i=0; i<8; i++)
    {
        float frequency = pow(2, i);
        float amplitude = 1 / frequency;
        
        float y= fmod(time*100, period);
        if(y < 0.01)
            trail[i].clear();
        
        float x = ofMap(sin(y * frequency * M_PI * 2 / period ) *amplitude, -1, 1, 0, ofGetWidth());

        trail[i].addVertex(x,y);
        if (trail[i].size() > 600){
            trail[i].getVertices().erase(trail[i].getVertices().begin());
        }
        trail[i].draw();
        
        ofDrawCircle(x, y, 10);
    }
    
}
