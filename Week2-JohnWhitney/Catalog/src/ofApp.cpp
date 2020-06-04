#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    path.arcNegative(420-290,296-120, 200, 200, 257, 198);
    path.arc        (430-290,233-120, 200, 200, 180, 243);
    path.arc        (200-290,200-120, 200, 200, 314, 332);
    path.close();
    path.setCircleResolution(120);
    path.setPolyWindingMode((ofPolyWindingMode) mode);
    
    shader.load("shadersGL3/shader");
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    
    path.setFillColor(ofColor(60,121,45,125));
    
    float r = 200;

    float angleDistance = 0.3926991; //radians
    float scale = ofMap(mouseX, 0,800, 1, 20 );
    path.scale(scale, scale);

    ofEnableBlendMode(OF_BLENDMODE_ADD);
    //16
    for(int i=0; i<16; i++){
        ofPushMatrix();
        float x =  400 + r * cos(angleDistance*i);
        float y =  400 + r * sin(angleDistance*i);
        ofTranslate(x,y);
        ofRotateDeg(ofGetElapsedTimef()*50 + 22.5*i);
      
        shader.begin();
        shader.setUniform1f("time", ofGetElapsedTimef());
        path.draw(0,0);
        shader.end();
            
        ofPopMatrix();
    }
    
   path.scale(1/scale, 1/scale);
    
    ofDrawBitmapString(to_string(mouseX), 20,20);
    ofDrawBitmapString(to_string(mouseY), 20,40);
    ofDrawBitmapString(to_string(scale), 20,60);
}

