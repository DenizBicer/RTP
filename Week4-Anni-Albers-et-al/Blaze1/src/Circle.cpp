//
//  Circle.cpp
//  Blaze1
//
//  Created by Deniz Bicer on 12.06.20.
//

#include "Circle.h"

ofPoint Circle::GetPoint(float degree)
{
    float x = _x + cos(degree * degToRad)*_r;
    float y = _y + sin(degree * degToRad)*_r;
    return ofPoint{x, y};
}

void Circle::SetOffset(float x, float y)
{
    _x+=x;
    _y+=y;
}
void Circle::SetPosition(float x, float y)
{
    _x=x;
    _y=y;
}
void Circle::Set(int x, int y, int r)
{
    _x=x;
    _y=y;
    _r=r;
}
