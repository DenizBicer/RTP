#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    appname = ofFilePath::getBaseName(ofFilePath::getCurrentExePath());
    original.load("input.png");
    imgPing.load("input.png");
    imgPong.allocate(imgPing.getWidth(),
                     imgPing.getHeight(),
                     OF_IMAGE_GRAYSCALE);

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
            
             imgLHS.setColor(i, j, lhs - rhs);
         }
    }
    imgLHS.update();
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

            
            imgLHS.setColor(i, j, color);
        }
    }
    imgLHS.update();
}
void ofApp::add( ofImage & imgLHS, ofImage & imgRHS){
    for (int i = 0; i < imgLHS.getWidth(); i++){
         for (int j = 0; j < imgLHS.getHeight(); j++){
             ofColor lhs = imgLHS.getColor(i, j);
             ofColor rhs = imgRHS.getColor(i, j);
            
             imgLHS.setColor(i, j, lhs + rhs);
         }
    }
    imgLHS.update();
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
                imgPing.setColor(i, j, color);
            }
       }
    imgPing.update();
}

void ofApp::dilateButtonClicked(){
    dilate(imgPing, imgPong);
    ofImage temp = imgPing;
    imgPing = imgPong;
    imgPong = temp;
    
}
void ofApp::eroseButtonClicked(){
    erose(imgPing, imgPong);
    ofImage temp = imgPing;
    imgPing = imgPong;
    imgPong = temp;
}
void ofApp::subtractButtonClicked(){
    subtract(imgPing, original);
}

void ofApp::xorButtonClicked(){
    XOR(imgPing, original);
}
void ofApp::addButtonClicked(){
    add(imgPing, original);
}

void ofApp::flipButtonClicked(){
    flip();
}

