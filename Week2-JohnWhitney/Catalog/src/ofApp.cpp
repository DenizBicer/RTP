#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    path.arcNegative(420,296, 200, 200, 257, 198 );
    path.arc(430,233, 200, 200, 180, 243);
    path.arc(200,200, 200, 200, 314, 332);
    path.close();
    path.setCircleResolution(120);
    path.setPolyWindingMode((ofPolyWindingMode) mode);
    
    //290, 120
}


//--------------------------------------------------------------
void ofApp::draw(){

    
    path.setFillColor(ofColor(60,121,45));
    path.draw(0,0);
    
    float r = 200;
    float angleDistance = 22.5;
    
    //16
//    for(int i=0; i<16; i++){
//        float x = r * cos(angleDistance*i);
//        float y = r * sin(angleDistance*i);
//
//        path.draw(x,y);
//    }
    
    ofDrawBitmapString(to_string(mouseX), 20,20);
    ofDrawBitmapString(to_string(mouseY), 20,40);

}

