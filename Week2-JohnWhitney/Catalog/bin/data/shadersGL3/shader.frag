#version 150

uniform float time;
out vec4 outputColor;

void main()
{
    vec2 st=gl_FragCoord.xy/vec2(800,800);
    float pct=distance(st,vec2(.5));
    
    vec4 color=vec4(1);
    
    float edge=(sin(time)+1)/4+.2;
    if(pct<edge)
    color=vec4(.24,.74,.176,1.);
    outputColor=color;
}