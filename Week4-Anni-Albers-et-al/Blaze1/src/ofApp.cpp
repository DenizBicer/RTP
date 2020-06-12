#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofSetColor(0);
    
    appname = ofFilePath::getBaseName(ofFilePath::getCurrentExePath());
    ofSetCircleResolution(100);
    
    float x = ofGetWidth()/2;
    float y = ofGetHeight()/2;
    sizes[0] = 10;
    sizes[1] = 35;
    sizes[2] = 104;
    sizes[3] = 171;
    sizes[4] = 241;
    sizes[5] = 311;
    for (int i=0; i < 6; i++)
    {
         circles[i].Set(x, y, sizes[i]);
    }
    
}

vector < ofPoint > ofApp::GenerateArrow(Circle a, Circle b, int sample, float thickness)
{
    vector < ofPoint > points;
    ofPoint p1 = a.GetPoint(sampleDegree * sample + thickness);
    ofPoint p2 = b.GetPoint(sampleDegree * sample + thickness);
    
    ofPoint m1 = a.GetPoint(sampleDegree * (sample+2) + thickness);
    ofPoint m2 = b.GetPoint(sampleDegree * (sample+2) + thickness);
    
    ofPoint mid = (m1 + m2)/2;
    
    points.push_back(p1);
    points.push_back(mid);
    points.push_back(p2);
    return points;
}
float easeOutBack(float x) {
    float c1 = 1.70158;
    float c3 = c1 + 1;
    
    return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
}
void ofApp::update(){
    float t = ofGetElapsedTimef() * 0.5;
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    
    for (int i=0; i < 5; i++)
    {
        float offset = ofMap(easeOutBack(i/4), 0, 1, 20, 30);
        
        float x = ofMap(ofNoise(i*0.1 + t), 0, 1, centerX-offset, centerX+offset);
        float y = ofMap(ofNoise(i*0.1 + t*2), 0, 1, centerY-offset, centerY+offset);
        float r = ofMap(ofNoise(i*0.1 + t), 0, 1, sizes[i] *0.5, sizes[i] *1.2);
        
        circles[i].Set(x, y, r);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    int sampleCount = 360/sampleDegree  * -1;
    float t = ofGetElapsedTimef() * 0.5;

    for (int i=0; i < 5; i++)
    {
        for(int j =0; j< sampleCount; j++)
        {
            vector < ofPoint > points1 =  GenerateArrow(circles[i], circles[i+1], j, 0);
            vector < ofPoint > points2  = GenerateArrow(circles[i], circles[i+1], j, ofMap(ofNoise((i* j)*0.1+ t), 0, 1, 2,7));
            
            ofPath path;
            path.setFillColor(0);
            path.moveTo(points1[0]);
            path.lineTo(points1[1]);
            path.lineTo(points1[2]);
            
            path.lineTo(points2[2]);
            path.lineTo(points2[1]);
            path.lineTo(points2[0]);
            
            path.draw();
            
        }
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

