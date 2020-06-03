#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
}

void drawHexagon(float centerX, float centerY, float r)
{
    ofPolyline line;
    for(int i = 0; i < 6; ++i) {
        float x = centerX + cos(i/6.0*2*M_PI)*r;
        float y = centerY + sin(i/6.0*2*M_PI)*r;
        line.addVertex(x,y);
    }
    line.close();
    line.draw();
}

float ofApp::getScale(int seed)
{
    float s = ofMap(seed, 0, 24, 0, 0.5);
    if(!goToCenter)
        return s;
    
    float t = ofGetElapsedTimef();
    float duration = t - centerStartTime;
    if(duration > centerLapseDuration)
        return 0;
    
    return ofLerp(s, 0, duration / centerLapseDuration);
}

float ofApp::getPhase(int seed)
{
    float p = ofMap(seed, 0, 24, 0, 0.5);
    if(!goToCenter)
        return p;
    
    float t = ofGetElapsedTimef();
    float duration = t - centerStartTime;
    if(duration > centerLapseDuration)
        return 0;
    
    return ofLerp(p, 0, duration /centerLapseDuration);
}

float ofApp::getVariety(int seed)
{
    if(!goToCenter)
        return seed;
   
    float t = ofGetElapsedTimef();
    float duration = t - centerStartTime;
    if(duration > centerLapseDuration)
          return 0;
      
    return ofLerp(seed, 0, duration /centerLapseDuration);
}

float ofApp::getCenterOffset()
{
    if(!goToCenter)
    return M_PI * 0.5;
    
    
    float t = ofGetElapsedTimef();
    float duration = t - centerStartTime;
    if(duration > centerLapseDuration)
          return 0;
      
    return ofLerp(M_PI * 0.5, 0, duration / centerLapseDuration);
}

//--------------------------------------------------------------
void ofApp::draw(){
    t += ofMap(sin(t), -1, 1, 0.01, 0.05);
    
    int screenWidth = ofGetWidth();
    int screenHeight = ofGetHeight();
    
    float centerX = screenWidth/2;
    float centerY = screenHeight/2;
    
    float width = screenWidth /2;
    float height = screenHeight /2;
    ofSeedRandom(0);
    for(int i=0; i< 24; i++)
    {
        float scale = getScale(i);
        float phase = getPhase(i);
        float variety = getVariety(i);
        
        float centerOffset = getCenterOffset();
        
        float x = ofMap(sin(3 * (t*scale + variety + phase) +centerOffset), -1, 1, centerX - width/2, centerX + width/2);
        float y = ofMap(sin(2 * (t*scale + variety + phase) ), -1, 1, centerY - height/2, centerY + height/2) ;
   
        
        if(t<10)
            ofDrawCircle(x, y, 5);
        else {
            float interpolate = ofClamp(t, 10, 20);
            float minSize = ofMap(interpolate, 10, 20, 1, 5);
            float maxSize = ofMap(interpolate, 10, 20, 5, 200);
            
            if(interpolate > 19)
            {
                //add colors 244 213 82
                //61 19 18
                float r = ofRandom(1);
                if(r < 0.3)
                    ofSetColor(255);
                else if( r> 0.3 && r < 0.9)
                    ofSetColor(244, 213, 82);
                else
                    ofSetColor(61, 19, 18);
            }
            
            ofSetLineWidth(2);
            drawHexagon(x, y, ofMap(sin(t + i * 0.1), -1, 1, minSize, maxSize));
            
            if(!goToCenter)
            {
                goToCenter = true;
                centerStartTime = ofGetElapsedTimef();
            }
            
        }
        
        ofSetColor(255);
        ofDrawBitmapString(to_string(t), 20,20);
    }
    
    
}
