#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(238, 231, 224);
    
    
    
    
}

void ofApp::update(){
    int verticeCount = 30;
    float stepSize = ofGetWidth()/verticeCount;
    float y = 7;
    float maxOffset = ofMap(mouseY, 0, 334, 0, 15);
    
    float pathOffset = ofGetHeight()/24 +2;
    float noiseZoom = ofMap(mouseX, 0, 400, 0.001, 0.2);
    ofSeedRandom(0);
    for(int i=0; i<24; i++)
    {
        ofPath path;
        path.lineTo(0,0);
        float pathY = pathOffset*i;
        
        for(int j=0; j<(verticeCount+2); j++)
        {
            float x = stepSize*j;
            
            float offSetX = ofNoise(x * noiseZoom ,(y+ pathY)* noiseZoom)
            * ofMap(ofRandom(1), 0, 1, -maxOffset, maxOffset);
            float offSetY = ofNoise((x+1) * noiseZoom, (y+ pathY) * noiseZoom)
            *ofMap(ofRandom(1), 0, 1, -maxOffset, maxOffset);
            
            path.lineTo(x+offSetX, offSetY);
        }
        
        for(int j=verticeCount+2; j>-1; j--)
        {
            float x = stepSize*j;
            
            float offSetX = ofNoise(x * noiseZoom ,(y+ pathY)* noiseZoom)
            * ofMap(ofRandom(1), 0, 1, -maxOffset, maxOffset);
            float offSetY = ofNoise((x+1) * noiseZoom, (y+ pathY) * noiseZoom)
            *ofMap(ofRandom(1), 0, 1, -maxOffset, maxOffset);
            
            path.lineTo(x+offSetX,y + offSetY);
        }
        
        path.close();
        path.setFillColor(ofColor(45, 41, 38));
        
        paths[i] = path;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float stepSize = ofGetHeight()/24 +2;
    float pathIndex = 0;
    for(auto path : paths)
    {
        path.draw(0, pathIndex*stepSize);
        pathIndex++;
    }
}

