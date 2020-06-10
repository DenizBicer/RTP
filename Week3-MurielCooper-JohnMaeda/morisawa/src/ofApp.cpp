#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //    font.load("FZGonta-Kana.otf", 200, true, true, true);
    
    ofTrueTypeFontSettings settings("FZGonta-Kana.otf", 200);
    settings.antialiased = true;
    settings.dpi = 72;
    settings.addRanges(ofAlphabet::Japanese);
    settings.contours = true;
    font.load(settings);
}
float easeOutSine(float x) {
  return sin((x * PI) / 2);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetColor(255);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(33, 30, 31);
    
    int maxRows = 200;
    ofRectangle rect = font.getStringBoundingBox("モリサワ", 0, 0);
//    float initialHeight = rect.height * 0.878;
    float initialHeight = rect.height * 0.7;

    float initialWidth = rect.width;

    float totalHeight = 165;
    vector < ofPath > paths = font.getStringAsPoints("モリサワ");

    for(int row = 1; row < maxRows; row++){
        ofPushMatrix();
        ofTranslate(0, totalHeight);
        float scaleFactor = 1 / (float)row;
        ofScale(scaleFactor);
        for(int column = 0; column < row; column++)
        {
//            font.drawString("モリサワ", initialWidth  * (float )column, 0);
            ofPushMatrix();
            ofTranslate( initialWidth  * (float )column, 0);
            for (int i = 0; i < paths.size(); i++){
                paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
                paths[i].draw();
//                vector < ofPolyline > lines = paths[i].getOutline();
//                for (int j = 0; j < lines.size(); j++){
//
//                    lines[j].setClosed(true);
//                    lines[j] = lines[j].getResampledBySpacing(3);
//                    lines[j] = lines[j].getSmoothed(mouseX*0.1);
//                    lines[j].draw();
//                }
            }
              ofPopMatrix();
        }
        ofPopMatrix();
        
        totalHeight += initialHeight*(1/(float)(row+1));

//        ofDrawBitmapString(to_string(scaleFactor), 20,row*10);

    }
    
        
        ofTranslate(300,300);
        
    
  
    
    ofSetColor(255,0,0);
//    ofNoFill();
//    ofRectangle rect = font.getStringBoundingBox("モリサワ", point.x, point.y);
//    ofDrawRectangle(rect);
//    ofFill();
//    ofDrawBitmapString(to_string(rect.x), 20,20);
//    ofDrawBitmapString(to_string(rect.y), 20,40);
//    ofDrawBitmapString(to_string(rect.width), 20,60);
//    ofDrawBitmapString(to_string(rect.height), 20,80);
//    ofDrawBitmapString(to_string(mouseY), 20,100);
//    ofDrawBitmapString(to_string(initialHeight), 20,120);
   screenshot.run();
}
