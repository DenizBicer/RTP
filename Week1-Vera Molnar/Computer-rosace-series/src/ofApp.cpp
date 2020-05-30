#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetColor(80,80,80);
    ofSetLineWidth(2);
    
    gui.setup();
//    gui.add(minGray.setup("minGray", 0, 10, 255));
//    gui.add(maxGray.setup("maxGray", 0, 10, 255));
    gui.add(noiseRate.setup("noiseRate", 0.01, 0.01, 1));
    gui.add(distance.setup("distance", 9, 1, 200));
    gui.add(cornerOffset.setup("cornerOffset", 9, 1, 200));
    gui.add(seed.setup("seed",0,0,100));

//    gui.add(stepCount.setup("stepCount", 10, 0, 300));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float unitCenterX = (float) ofGetHeight()/4;
    float unitCenterY = (float) ofGetHeight()/4;
    float distance = 8.6;
    float variation = distance/6;
    
    ofSeedRandom(seed);


    for(int i=1; i< 31; i++)
    {
        drawSquareOne(unitCenterX, unitCenterY, i*distance, variation);
        drawSquareTwo(unitCenterX*3, unitCenterY, distance, variation, i);
        drawSquareThree(unitCenterX, unitCenterY*3, distance, variation, i);
        
        if( i <21)
            drawSquareFour(unitCenterX*3, unitCenterY*3, distance * 1.5, variation, i);
    }
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::drawSquareOne(float centerX, float centerY, float size, float variation){
    ofPolyline line;
    float halfSize = size / 2;
    
    ofVec3f LT, LB, RT, RB;
    LT.set(centerX-halfSize, centerY-halfSize, 0);
    LB.set(centerX-halfSize, centerY+halfSize-variation, 0);
    RT.set(centerX+halfSize-variation, centerY-halfSize, 0);
    RB.set(centerX+halfSize-variation, centerY+halfSize-variation, 0);
    
    ofVec3f corners [] = {LT, LB, RB, RT};
    
    ofVec3f firstVertex;
    ofVec3f secondVertex;
    
    for(int i=0; i<4; i++)
    {
        firstVertex = corners[i];
        secondVertex = corners[(i+1)%4];
        
        line.clear();
        ofSetColor(ofMap(ofNoise(secondVertex.x*0.01, secondVertex.y*0.01), 0, 1, 123, 190));
        line.addVertex(firstVertex);
        line.addVertex(secondVertex);
        line.draw();
    }
}

//--------------------------------------------------------------
void ofApp::drawSquareTwo(float centerX, float centerY, float distance, float variation, int index)
{
    ofPolyline line;
    float halfSize = index*distance / 2;
    
    bool isDeviated = index == 15;
    float deviation = distance / 2 * isDeviated;
    
    
    ofVec3f LT, LB, RT, RB;
    LT.set(centerX-halfSize + deviation, centerY-halfSize - deviation, 0);
    LB.set(centerX-halfSize + deviation, centerY+halfSize -deviation - variation, 0);
    RT.set(centerX+halfSize - deviation -variation, centerY + deviation -halfSize, 0);
    RB.set(centerX+halfSize + deviation -variation, centerY+halfSize + deviation -variation, 0);
    
    ofVec3f corners [] = {LT, LB, RB, RT};
    
    ofVec3f firstVertex;
    ofVec3f secondVertex;
    
    for(int i=0; i<4; i++)
    {
        firstVertex = corners[i];
        secondVertex = corners[(i+1)%4];
        
        line.clear();
        ofSetColor(ofMap(ofNoise(firstVertex.x*0.01, firstVertex.y*0.01), 0, 1, 123, 190));
        line.addVertex(firstVertex);
        line.addVertex(secondVertex);
        line.draw();
    }
}


float easeInSine(float x) {
  return 1 - cos((x * PI) / 2);
}


//--------------------------------------------------------------
void ofApp::drawSquareThree(float centerX, float centerY, float distance, float variation, int index)
{
    ofPolyline line;
    float halfSize = index*distance / 2;

    float messiness = easeInSine(1 - (float)index/30);
    float deviationStrength = messiness* 10;
    float rotationAngle = ofRandom(-45, 45) * messiness *0.5;

    ofVec3f LT, LB, RT, RB;
    
    LT.set( - halfSize + ofRandom(-deviationStrength, deviationStrength),
            - halfSize + ofRandom(-deviationStrength, deviationStrength),
           0);
    LB.set( - halfSize + ofRandom(-deviationStrength, deviationStrength),
            + halfSize + ofRandom(-deviationStrength, deviationStrength)
           , 0);
    RT.set( + halfSize + ofRandom(-deviationStrength, deviationStrength),
            - halfSize + ofRandom(-deviationStrength, deviationStrength) ,
           0);
    RB.set( + halfSize + ofRandom(-deviationStrength, deviationStrength),
            + halfSize + ofRandom(-deviationStrength, deviationStrength),
           0);
    
    ofVec3f corners [] = {LT, LB, RB, RT};
    
    ofVec3f firstVertex;
    ofVec3f secondVertex;
    
    for(int i=0; i<4; i++)
    {
        firstVertex = corners[i];
        secondVertex = corners[(i+1)%4];
        
        line.clear();
        
        ofPushMatrix();
        
        ofTranslate(centerX, centerY);
        ofRotateDeg(rotationAngle);


        ofSetColor(ofMap(ofNoise(firstVertex.x*0.01, firstVertex.y*0.01), 0, 1, 123, 190));
        line.addVertex(firstVertex);
        line.addVertex(secondVertex);
        line.draw();
        
        ofPopMatrix();
    }
}

void ofApp::drawSquareFour(float centerX, float centerY, float distance, float variation, int index)
{
    ofPolyline line;
    float halfSize = index*distance / 2;

    ofVec3f LT, LB, RT, RB;
    float offset = cornerOffset;
    
    LT.set( - halfSize + ofRandom(-offset, offset),
            - halfSize + ofRandom(-offset, offset),
           0);
    LB.set( - halfSize + ofRandom(-offset, offset),
            + halfSize + ofRandom(-offset, offset),
           0);
    RT.set( + halfSize + ofRandom(-offset, offset),
            - halfSize + ofRandom(-offset, offset),
           0);
    RB.set( + halfSize + ofRandom(-offset, offset),
            + halfSize + ofRandom(-offset, offset),
           0);
    
    ofVec3f corners [] = {LT, LB, RB, RT};
    
    ofVec3f firstVertex;
    ofVec3f lastVertex;
    
    for(int i=0; i<4; i++)
    {
        firstVertex = corners[i];
        lastVertex = corners[(i+1)%4];
        
        line.clear();
        
        ofPushMatrix();
               
        ofTranslate(centerX, centerY);
        
        ofSetColor(ofMap(ofNoise(firstVertex.x*0.01, firstVertex.y*0.01), 0, 1, 123, 190));
        line.addVertex(firstVertex);
        
        ofVec2f direction;
        direction.set((lastVertex-firstVertex).getNormalized());
        
        ofVec2f perpendicular = direction.getPerpendicular();
        
        int stepCount = 120;
        float stepSize =firstVertex.distance(lastVertex)/(float)stepCount;
        
        float ignoreNoiseStep = ofMap(ofRandom(1), 0, 1, stepCount/2, stepCount);
        
        for(int j=0; j <stepCount; j++)
        {
            float noise = (ofSignedNoise(index + i + j *noiseRate))* ofApp::distance;
            noise = j > ignoreNoiseStep ? 0 : noise;
            ofVec2f v =  firstVertex + j*direction*stepSize + perpendicular * stepSize * noise;
          line.addVertex(v.x, v.y, 0);
        }
        
        line.addVertex(lastVertex);
        line.draw();
        
        ofPopMatrix();
    }
}
