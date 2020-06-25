#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    appname = ofFilePath::getBaseName(ofFilePath::getCurrentExePath());
    
    gui.setup();
    dilateButton.addListener(this, &ofApp::dilateButtonClicked);
    eroseButton.addListener(this, &ofApp::eroseButtonClicked);
    subtractButton.addListener(this, &ofApp::subtractButtonClicked);
    addButton.addListener(this, &ofApp::addButtonClicked);
    xorButton.addListener(this, &ofApp::xorButtonClicked);
    flipButton.addListener(this, &ofApp::flipButtonClicked);
    
    gui.add(dilateButton.setup("dilate"));
    gui.add(eroseButton.setup("erose"));
    gui.add(subtractButton.setup("subtract"));
    gui.add(addButton.setup("add"));
    gui.add(xorButton.setup("xor"));
    gui.add(flipButton.setup("flip"));
    
//    int width = ofGetWidth();
//    int height = ofGetHeight();
//
//    fbo.allocate(width, height, GL_RGBA);
//
//    fbo.begin();
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofSeedRandom(0);
//    ofBackground(0);
//    ofSetColor(255);
//    ofNoFill();
//    ofSetLineWidth(10);
//    ofPoint points[10];
//
//    for(int i=0; i<10; i++)
//    {
//        int x = ofRandom(width*0.5) + width*0.25;
//        int y = ofRandom(height*0.5) + height*0.25;
//        points[i] = ofPoint(x,y);
//        ofDrawRectangle(x,y,50,50);
//
////        for(int j=0; j<i; j++)
////        {
////            int d = points[i].distance(points[j]);
////            if(d < 50)
////                ofDrawLine(points[i], points[j]);
////        }
//    }
//
//    fbo.end();
    
    
//    ofPixels pixels;
//    fbo.readToPixels(pixels);
//    original.setFromPixels(pixels);
//    imgPing.setFromPixels(pixels);
//    imgPong.setFromPixels(pixels);
    
    original.load("input2.png");
    imgPing.load("input2.png");
    imgPong.allocate(imgPing.getWidth(),
                     imgPing.getHeight(),
                     OF_IMAGE_GRAYSCALE);
    
    
}
void ofApp::update(){
//    int t = ofGetElapsedTimef();
////    if(t%4 == 0)
//    {
////        dilateButtonClicked();
//        dilateButtonClicked();
//        subtractButtonClicked();
//    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    imgPing.draw(0, 0);
    gui.draw();
    
    
}

void ofApp::keyReleased(int key){
    switch (key) {
        case ' ': {
            ofImage image;
            image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            
            image.save(appname+"_"+ofGetTimestampString()+".png");
            break;
        }
        case 'r': {
            imgPing = original;
            break;
        }
        case 'a': {
            int numRounds = 4;
            bool useDilate = ofRandom(0, 1) < 0.8;
            for (int i = 0; i < numRounds; ++i) {
                if (useDilate) {
                    dilateButtonClicked();
                } else {
                    eroseButtonClicked();
                    useDilate = true;
                }
            }
            
            subtractButtonClicked();
            break;
        }
    }
}
void ofApp::dilate( ofImage & imgSrc, ofImage & imgDest){
    
    // assumptions!
    // img1 / img2 same w/h
    // both grayscale / binary images
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            
            // neighbors
            // edges
            
            int i_m_1 = ofClamp(i-1, 0, imgSrc.getWidth()-1);
            int i_p_1 = ofClamp(i+1, 0, imgSrc.getWidth()-1);
            int j_m_1 = ofClamp(j-1, 0, imgSrc.getHeight()-1);
            int j_p_1 = ofClamp(j+1, 0, imgSrc.getHeight()-1);
            
            // neighbor values
            
            ofColor n_ = imgSrc.getColor(i,j_p_1);
            ofColor ne = imgSrc.getColor(i_p_1,j_p_1);
            ofColor e_ = imgSrc.getColor(i_p_1,j);
            ofColor se = imgSrc.getColor(i_p_1,j_m_1);
            ofColor s_ = imgSrc.getColor(i,j_m_1);
            ofColor sw = imgSrc.getColor(i_m_1,j_m_1);
            ofColor w_ = imgSrc.getColor(i_m_1,j);
            ofColor nw = imgSrc.getColor(i_m_1,j_p_1);
            
            if (
                n_.getBrightness() > 127 ||
                ne.getBrightness() > 127 ||
                e_.getBrightness() > 127 ||
                se.getBrightness() > 127 ||
                s_.getBrightness() > 127 ||
                sw.getBrightness() > 127 ||
                w_.getBrightness() > 127 ||
                nw.getBrightness() > 127
                ){
                imgDest.setColor(i,j, ofColor(255));
            } else {
                imgDest.setColor(i,j, ofColor(0));
            }
        }
    }
    imgDest.update();
}
void ofApp::erose( ofImage & imgSrc, ofImage & imgDest){
    
    // assumptions!
    // img1 / img2 same w/h
    // both grayscale / binary images
    
    for (int i = 0; i < imgSrc.getWidth(); i++){
        for (int j = 0; j < imgSrc.getHeight(); j++){
            
            // neighbors
            // edges
            
            int i_m_1 = ofClamp(i-1, 0, imgSrc.getWidth()-1);
            int i_p_1 = ofClamp(i+1, 0, imgSrc.getWidth()-1);
            int j_m_1 = ofClamp(j-1, 0, imgSrc.getHeight()-1);
            int j_p_1 = ofClamp(j+1, 0, imgSrc.getHeight()-1);
            
            // neighbor values
            
            ofColor n_ = imgSrc.getColor(i,j_p_1);
            ofColor ne = imgSrc.getColor(i_p_1,j_p_1);
            ofColor e_ = imgSrc.getColor(i_p_1,j);
            ofColor se = imgSrc.getColor(i_p_1,j_m_1);
            ofColor s_ = imgSrc.getColor(i,j_m_1);
            ofColor sw = imgSrc.getColor(i_m_1,j_m_1);
            ofColor w_ = imgSrc.getColor(i_m_1,j);
            ofColor nw = imgSrc.getColor(i_m_1,j_p_1);
            
            if (
                n_.getBrightness() < 127 ||
                ne.getBrightness() < 127 ||
                e_.getBrightness() < 127 ||
                se.getBrightness() < 127 ||
                s_.getBrightness() < 127 ||
                sw.getBrightness() < 127 ||
                w_.getBrightness() < 127 ||
                nw.getBrightness() < 127
                ){
                imgDest.setColor(i,j, ofColor(0));
            } else {
                imgDest.setColor(i,j, ofColor(255));
            }
        }
    }
    imgDest.update();
}
void ofApp::subtract( ofImage & imgLHS, ofImage & imgRHS){
    for (int i = 0; i < imgLHS.getWidth(); i++){
        for (int j = 0; j < imgLHS.getHeight(); j++){
            ofColor lhs = imgLHS.getColor(i, j);
            ofColor rhs = imgRHS.getColor(i, j);
            
            imgRHS.setColor(i, j, lhs - rhs);
        }
    }
    imgRHS.update();
}
void ofApp::XOR(ofImage & imgLHS, ofImage & imgRHS){
    for (int i = 0; i < imgLHS.getWidth(); i++){
        for (int j = 0; j < imgLHS.getHeight(); j++){
            ofColor lhs = imgLHS.getColor(i, j);
            ofColor rhs = imgRHS.getColor(i, j);
            
            bool lB = lhs.getBrightness()>127;
            bool rB = rhs.getBrightness()>127;
            bool colorCode =  lB ^ rB;
            ofColor color;
            if(colorCode)
                color = ofColor(255);
            else
                color = ofColor(0);
            
            
            imgRHS.setColor(i, j, color);
        }
    }
    imgRHS.update();
}
void ofApp::add( ofImage & imgLHS, ofImage & imgRHS){
    for (int i = 0; i < imgLHS.getWidth(); i++){
        for (int j = 0; j < imgLHS.getHeight(); j++){
            ofColor lhs = imgLHS.getColor(i, j);
            ofColor rhs = imgRHS.getColor(i, j);
            
            imgRHS.setColor(i, j, lhs + rhs);
        }
    }
    imgRHS.update();
}

void ofApp::flip(){
    for (int i = 0; i < imgPing.getWidth(); i++){
        for (int j = 0; j < imgPing.getHeight(); j++){
            ofColor c = imgPing.getColor(i, j);
            
            ofColor color;
            if(c.getBrightness() < 127)
                color = ofColor(255);
            else
                color = ofColor(0);
            imgPong.setColor(i, j, color);
        }
    }
    imgPong.update();
}

void ofApp::swap(){
    ofImage temp = imgPing;
    imgPing = imgPong;
    imgPong = temp;
}

void ofApp::dilateButtonClicked(){
    dilate(imgPing, imgPong);
    swap();
    
}
void ofApp::eroseButtonClicked(){
    erose(imgPing, imgPong);
     swap();
}
void ofApp::subtractButtonClicked(){
    subtract(imgPing, imgPong);
    swap();
}

void ofApp::xorButtonClicked(){
    XOR(imgPing, imgPong);
     swap();
}
void ofApp::addButtonClicked(){
    add(imgPing, imgPong);
     swap();
}

void ofApp::flipButtonClicked(){
    flip();
     swap();
}

void ofApp::applyBlur(){
    subtract(original, imgPong);
    swap();

}



