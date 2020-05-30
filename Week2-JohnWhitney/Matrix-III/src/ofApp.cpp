#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
}

void drawHexagon(float centerX, float centerY, float r)
{
    ofPolyline line;
    for(int i = 0; i < 6; ++i) {
        float x = centerX + cos(i/6.0*2*M_PI)*r;
        float y = centerY + sin(i/6.0*2*M_PI)*r;
        line.addVertex(x,y);
    }
    line.close();
    line.draw();
}

//--------------------------------------------------------------
void ofApp::draw(){
    float t = ofGetElapsedTimef();
    int screenWidth = ofGetWidth();
    int screenHeight = ofGetHeight();
    
    float centerX = screenWidth/2;
    float centerY = screenHeight/2;
    
    float width = screenWidth /2;
    float height = screenHeight /2;
    
    for(int i=0; i< 24; i++)
    {
        float scale = ofMap(i, 0, 80, 0, 10);

        float x = ofMap(sin(3 * (t*scale +i) + M_PI * 0.5), -1, 1, centerX - width/2, centerX + width/2);
        float y = ofMap(sin(2 * (t*scale +i) ), -1, 1, centerY - height/2, centerY + height/2) ;
        
        ofSetLineWidth(2);
        drawHexagon(x, y, ofMap(sin(t + i * 0.1), -1, 1, 20, 200));
    }
    
    
}
