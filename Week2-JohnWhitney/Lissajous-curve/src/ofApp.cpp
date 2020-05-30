#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    
    gui.add(a.setup("a", 0, 0 ,1));
    gui.add(b.setup("b", 0, 0 ,1));
    gui.add(d.setup("d", 0, 0 ,1));
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float t = ofGetElapsedTimef();
    float width = ofGetWidth();
    float height = ofGetHeight();
    
    float cellW = width / 7;
    float cellH = height / 7;
    
    float stepX = cellW /2;
    float stepY = cellH /2;
    
    for(int i=1; i< 8; i++)
    {
        for(int j=1; j<8; j++)
        {
            float x = ofMap(sin(i * t + M_PI * 0.5), -1, 1, 0, cellW) + cellW* (i-1);
            float y = ofMap(sin(j * t ), -1, 1, 0, cellH) + cellH*(j-1) ;
            
            ofDrawCircle(x, y, 5);
            
            int trailIndex = i * 8 +j;
            trail[trailIndex].addVertex(x,y);
            if (trail[trailIndex].size() > 600){
                trail[trailIndex].getVertices().erase(trail[trailIndex].getVertices().begin());
            }
            trail[trailIndex].draw();
        }
    }
    
    //    gui.draw();
    
}

