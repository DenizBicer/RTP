#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyReleased(int key);
    
    void dilate( ofImage & imgSrc, ofImage & imgDest);
    void erose( ofImage & imgSrc, ofImage & imgDest);
    void subtract( ofImage & imgLHS, ofImage & imgRHS);
    void add( ofImage & imgLHS, ofImage & imgRHS);
    void XOR( ofImage & imgLHS, ofImage & imgRHS);
    void flip();
    void swap();
    void applyBlur();
    
    void dilateButtonClicked();
    void eroseButtonClicked();
    void subtractButtonClicked();
    void addButtonClicked();
    void xorButtonClicked();
    void flipButtonClicked();

    ofFbo fbo;
    
    ofImage original;
    ofImage imgPing;
    ofImage imgPong;
    
    ofxPanel gui;
    
    ofxButton dilateButton;
    ofxButton eroseButton;
    ofxButton subtractButton;
    ofxButton xorButton;
    ofxButton addButton;
    ofxButton flipButton;
    
    int width = 400;
    int height = 400;

    string appname;
};
