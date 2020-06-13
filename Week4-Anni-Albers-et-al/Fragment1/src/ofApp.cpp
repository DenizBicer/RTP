#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    appname = ofFilePath::getBaseName(ofFilePath::getCurrentExePath());
    ofSetBackgroundColor(255);
}


vector < ofPoint > ofApp::CreateArrow(ofPolyline top, ofPolyline mid, ofPolyline bottom, float percentage ){
    vector < ofPoint > points;
    points.push_back(top.getPointAtPercent(percentage));
    points.push_back( mid.getPointAtPercent(powf(percentage, 3)));
    points.push_back(bottom.getPointAtPercent(percentage));
    return points;
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    
    ofPolyline topLine, midLine, bottomLine;
    
    topLine.addVertex(50, 20);
    topLine.addVertex(445, 20);
    
    midLine.addVertex(238, 168);
    midLine.addVertex(364, 109);
    
    bottomLine.addVertex(19, 342);
    bottomLine.addVertex(463, 342);
    
    
    for(int i=0; i < 10; i++)
    {
        float percentage = ofMap(i, 0, 9, 0, 1);
        float thicknessPercentage = ofMap(i+0.5, 0, 9, 0, 1);

        vector < ofPoint > firstArrow = CreateArrow (topLine, midLine, bottomLine, percentage);
        vector < ofPoint > secondArrow = CreateArrow (topLine, midLine, bottomLine, thicknessPercentage);
        
        ofPath path;
        path.setFillColor(0);
        path.moveTo(firstArrow[0]);
        path.lineTo(firstArrow[1]);
        path.lineTo(firstArrow[2]);
        
        path.lineTo(secondArrow[2]);
        path.lineTo(secondArrow[1]);
        path.lineTo(secondArrow[0]);
        path.draw();
    }
}

void ofApp::keyReleased(int key){
    // make a screenshot of the app window when "p" key is released
    switch (key) {
        case ' ':
            ofImage image;
            image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            
            image.save(appname+"_"+ofGetTimestampString()+".png");
            break;
    }
}
