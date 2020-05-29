#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);

//    shader.load("shadersGL3/shader");
}

//--------------------------------------------------------------
void ofApp::update(){
    //
}

//--------------------------------------------------------------
void ofApp::draw(){
    float stepSize = 7.14;
    float width = ofGetWidth();
    float height = ofGetHeight();
    float thickness = stepSize/2;
    ofSetColor(24, 46, 96);

// horizontal lines
    for(int i=0; i< 28; i++)
    {
        ofDrawRectangle(0, stepSize*i, width, thickness);
    }

// vertical lines
    for(int i=0; i< 84; i++)
    {
        float x = stepSize*i;
        float y = height;
        for (auto point : drawnPoints){
          
            float distance = abs(x - point.x);
            if(distance <10)
            {
                y = point.y;
            }

        }
        

        ofSetColor(24, 46, 96);
        ofDrawRectangle(x, y, thickness, height - y);
        
        float x2 = x +thickness;
        float y2 = height;
        for (auto point : drawnPoints){
          
            float distance =abs( x2 - point.x);
            if(distance <10)
            {
                y2 = point.y;
            }

        }
        
        ofSetColor(255);
        ofDrawRectangle(x2, y2, stepSize/2, height -y2);
    }
    
    
//    shader.begin();
//
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
//
//    shader.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    drawnPoints.push_back(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
