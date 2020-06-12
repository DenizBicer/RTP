//
//  Circle.h
//  Blaze1
//
//  Created by Deniz Bicer on 12.06.20.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "ofMain.h"

class Circle {
public:
    Circle() {}
    
    Circle(int x, int y, int r)
        : _x(x), _y(y), _r(r)
    {}
    
    ofPoint GetPoint(float degree);
    void SetOffset(float x, float y);
    void SetPosition(float x, float y);
    void Set(int x, int y, int r);
    
    int _x{ 0 };
    int _y{ 0 };
    int _r{ 0 };
    const float degToRad = M_PI / 180;

};
#endif /* Circle_hpp */
