#version 150

out vec4 outputColor;

const float e=2.71828;

float gaussian(float x)
{
    float a=.9;
    float b=.5;
    float c=.1;
    return a*pow(e,-(x-b)*(x-b)/(2*c*c));
}
//	<https://www.shadertoy.com/view/4dS3Wd>
//	By Morgan McGuire @morgan3d, http://graphicscodex.com
//
float hash(float n){return fract(sin(n)*1e4);}
float hash(vec2 p){return fract(1e4*sin(17.*p.x+p.y*.1)*(.1+abs(sin(p.y*13.+p.x))));}

float noise(float x){
    float i=floor(x);
    float f=fract(x);
    float u=f*f*(3.-2.*f);
    return mix(hash(i),hash(i+1.),u);
}

void main()
{
    vec2 st=gl_FragCoord.xy/vec2(600,200);
    
    float x=st.x*60;
    float y=st.y*20;
    
    x=step(.5,fract(x));
    y=step(.5,fract(y));
    
    float n=noise1(st.x*8)*.5-.5;
    float secondHalf=step(.5,st.x);
    n=(1-secondHalf)*n*2+n*secondHalf;
    
    float g=gaussian(st.x);
    
    if(st.x<.5)
    n=.5+(g+n)*.2;
    else
    n=g;
    
    n=smoothstep(0,1,n)*.9;
    float orientation=x;
    
    if(st.y>n&&st.y>.2)
    orientation=y;
    
    vec3 color=vec3(.094,.175,.384);
    color=(1-orientation)*vec3(1.)+orientation*color;
    
    outputColor=vec4(color,1.);
}