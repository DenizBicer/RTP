Course details [link](https://sfpc.io/recreatingthepast-spring2020/)

classmates web ring:

* [Norm](https://www.are.na/norman-o-hagan/recreating-the-past-shenanigans-summer-2020)

## Table of Contents

 * [Week 1 - Vera Molnar](#week-1---vera-molnar)
  * [Week 2 - John Whitney](#week-2---john-whitney)
     * [Harmony](#harmony)
     * [Lissajous-curve](#lissajous-curve)
     * [Matrix III](#matrix-iii)
     * [Catalog](#catalog)
  * [Week 3](#week-3)
     * [Morisawa](#morisawa)
  * [Week4-Anni-Albers-et-al](#week4-anni-albers-et-al)
     * [Blaze 1 - Bridget Riley](#blaze-1---bridget-riley)
     * [Fragments 1 -Bridget Riley](#fragments-1--bridget-riley)

## Week 1 - Vera Molnar 

| Carrés en 2 positions                         | Computer-rosace-series                 | de la serie 100 carres                 |
| --------------------------------------------- | -------------------------------------- | -------------------------------------- |
| ![01](https://i.imgur.com/kuaiLxf.gif)        | ![01](https://i.imgur.com/giTlWIK.png) | ![01](https://i.imgur.com/Hbm1mA5.png) |
| du cycle inclinaisions                        | Horizontales                           | Sainte-Victoire On Line                |
| ![01](![img](https://i.imgur.com/YW03m9L.png) | ![01](https://i.imgur.com/L55vmrw.gif) | ![01](https://i.imgur.com/otKu2B9.gif) |



## Week 2 - John Whitney

### Harmony



![harmony original](https://i.imgur.com/lK0W2iF.png)

| 01 -  Wrong map range                                                                          | 02 - Wrong variable in sin                                                  | 03 -  Worked!                                                                                      |
| :--------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------- |
| ![01](https://i.imgur.com/45cEeYh.gif)                                                         | ![02](https://i.imgur.com/YZiDR5e.gif)                                      | ![03](https://i.imgur.com/b75lmMf.gif)                                                             |
| ```float x = ofMap(sin(time*frequency )*amplitude, -amplitude, amplitude, 0, ofGetWidth());``` | ` float x = ofMap(sin(time * M_PI * 2 / period ), -1, 1, 0, ofGetWidth());` | `    float x = ofMap(sin(y * frequency * M_PI * 2 / period ) *amplitude, -1, 1, 0, ofGetWidth());` |
| ` -amplitude, amplitude` range should have been `-1, 1`                                        | instead of `time` use `y` value.                                            |                                                                                                    |

### Lissajous-curve

Recreating the below curve table:

![curve-table](https://i.imgur.com/5MlrCjp.gif)

Equation: ![equation](https://i.imgur.com/j2LBAZH.png)

The table is changing two parameters **a** and **b**.

Rows are increasing the **a** value from top to down. Range is [1,7]

Columns are increasing the **b** value from left to right . Range is [1,7]



| 01 - no grid                           | 02 - wrong spacing at grid             | 03 - worked!                           |
| -------------------------------------- | -------------------------------------- | -------------------------------------- |
| ![01](https://i.imgur.com/jnlFjGp.gif) | ![02](https://i.imgur.com/U9Yzjbs.gif) | ![03](https://i.imgur.com/OHlr0wr.gif) |

**01 code snippet**

```c++
    float t = ofGetElapsedTimef();
    float width = ofGetWidth();
    float height = ofGetHeight();
    for(int i=1; i< 8; i++)
    {
        for(int j=1; j<8; j++)
        {
            float x = ofMap(sin(i * t + M_PI * 0.5), -1, 1, 0, width);
            float y = ofMap(sin(j * t ), -1, 1, 0, height) ;
            ofDrawCircle(x, y, 5);
        }
    }
```



**03 code snippet**

```c++
    for(int i=1; i< 8; i++)
    {
        for(int j=1; j<8; j++)
        {
            float x = ofMap(sin(i * t + M_PI * 0.5), -1, 1, 0, cellW) + cellW* (i-1);
            float y = ofMap(sin(j * t ), -1, 1, 0, cellH) + cellH*(j-1) ;
            
            ofDrawCircle(x, y, 5);
        }
    }
```

### Matrix III

recreating snippets of [Matrix III - John whitney](https://www.youtube.com/watch?v=ZrKgyY5aDvA)



| 01                                     | 02                                                                                                                                                                | 03                                                                                                                  |
| -------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------- |
| ![01](https://i.imgur.com/Oba8TjD.gif) | ![02](https://i.imgur.com/dkDoLKJ.gif)                                                                                                                            | ![03](https://i.imgur.com/IEgtWXB.gif)                                                                              |
|                                        | removing the **i** from equation made them align too much. Also they should have collapsed in the middle but because of `+ M_PI * 0.5`  it collapsed on the side. | This version is closer to the original but they align to a lign before collapsing instead of coming from all sides. |



**01 code snippet**

```c++
for(int i=0; i< 24; i++)
    {
        float scale = ofMap(i, 0, 80, 0, 10);

        float x = ofMap(sin(3 * (t*scale +i) + M_PI * 0.5),
                        -1, 1,
                        centerX - width/2, centerX + width/2);
        float y = ofMap(sin(2 * (t*scale +i) ),
                        -1, 1,
                        centerY - height/2, centerY + height/2) ;
  
        ofSetLineWidth(2);
        drawHexagon(x, y, ofMap(sin(t + i * 0.1), -1, 1, 20, 200));
    }
```

### Catalog

recreating snippets of [Catalog](https://youtu.be/TbV7loKp69s?t=225)

**Creating the basic shape**

I studied the fan like shape using Figma. 

| ![study1](https://i.imgur.com/uiH5n8Y.png)                    | ![study2](https://i.imgur.com/j9GK8dw.png)                                    |
| ------------------------------------------------------------- | ----------------------------------------------------------------------------- |
| I first placed circles to create the shape as an intersection | Then found the origin points and the angles to recreate the arcs using ofPath |

```c++
    ofPath path;
		path.arcNegative(420-290,296-120, 200, 200, 257, 198);
    path.arc        (430-290,233-120, 200, 200, 180, 243);
    path.arc        (200-290,200-120, 200, 200, 314, 332);
    path.close();
    path.setCircleResolution(120);
    path.setPolyWindingMode((ofPolyWindingMode) 2);
    
```

above code snippet renders the following shape

![shape](https://i.imgur.com/kc56KON.png)

Code details:

- in order to move the shape origin to the middle every center point is offsetted by **(290,120)**. 
- **arc** draws the path in *clockwise* and **arcNegative** in *counter-clockwise*
- whole shape is drawn in *clockwise* 
- Tried different **PolyWindingMode**s and decided on using *OF_POLY_WINDING_POSITIVE* (2) which closed the path without artefacts.

**Iterations**

| 01                                                                                                                          | 02                                                               |
| --------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------- |
| ![img](https://i.imgur.com/XCJwepG.png)                                                                                     | ![02](https://i.imgur.com/dJ4VlXX.gif)                           |
| The position of the arcs are correct but couldn't figure out the rotation yet. The pivot was not set properly for rotation. | The **mouseX** position is used to change the size of the shape. |

**02**

- used  ` ofEnableBlendMode(OF_BLENDMODE_ADD)` to make the overlapping regions emit more light
- used a **fragment shader** to color parts of the ofPath 



## Week 3

### Morisawa

| Original Work                                 | **Reproduction**                                                  |
| --------------------------------------------- | ----------------------------------------------------------------- |
| ![morisawa2](https://i.imgur.com/8LXdGtL.jpg) | ![devImg2020-06-10-19-07-13-086](https://i.imgur.com/K6mjQuC.jpg) |



Used the [FZGonta-kana](http://zone108.main.jp/font/fz-gonta-kana.html) font. Unzipping the font under MacOS was not trivial. 

I found this command from [here](https://github.com/CocoaPods/CocoaPods/issues/7711) to unzip the font file that has japanese characters as a name:

`$ ditto -V -x -k --sequesterRsrc --rsrc FILENAME.ZIP DESTINATIONDIRECTORY`



[fix screenshot colors](https://forum.openframeworks.cc/t/ofimage-grabscreen-distorting-colours/34318/6): line 1917 of “ofGLRenderer.cpp”:

`auto pixelFormat = OF_PIXELS_RGBA; `



I suppose, becuase of the difference at the font the reproduction looks darker.

## Week4-Anni-Albers-et-al

### Blaze 1 - Bridget Riley

| Original                                     | Recreation                                                              |
| -------------------------------------------- | ----------------------------------------------------------------------- |
| ![original](https://i.imgur.com/NrLHIJf.jpg) | ![Blaze1Debug_2020-06-12-22-06-24-703](https://i.imgur.com/gpp1uZT.gif) |



**Shape Study**

| Extracting the building blocks         | seperating circles                     | finding points to draw an arrow between circles |
| -------------------------------------- | -------------------------------------- | ----------------------------------------------- |
| ![01](https://i.imgur.com/HGutHlN.png) | ![02](https://i.imgur.com/jeIlsZq.png) | ![03](https://i.imgur.com/otOzwDt.png)          |

| Iterations                                     | Noise on circles                          |
| ---------------------------------------------- | ----------------------------------------- |
| ![iterations](https://i.imgur.com/gsYV4O6.gif) | ![noise](https://i.imgur.com/gpp1uZT.gif) |



**Experiments** 



| Noise by sampled degree (thickness)     | Noise by cicle (thickness)              |
| --------------------------------------- | --------------------------------------- |
| ![e01](https://i.imgur.com/YQnwjTc.gif) | ![e02](https://i.imgur.com/LIr308J.gif) |

|                                         |                                         |
| --------------------------------------- | --------------------------------------- |
| ![e03](https://i.imgur.com/kMKo5F7.gif) | ![e04](https://i.imgur.com/IgfpPOX.gif) |

| noise on sample degree                  | noise on sample degree with a smaller range | fix sample count and change sample degree |
| --------------------------------------- | ------------------------------------------- | ----------------------------------------- |
| ![e05](https://i.imgur.com/DOl9bDh.gif) | ![e06](https://i.imgur.com/0YsGbYb.gif)     | ![eo7](https://i.imgur.com/fmxWDB0.gif)   |



### Fragments 1 -Bridget Riley

| Original                                     | Recreation                                                                 |
| -------------------------------------------- | -------------------------------------------------------------------------- |
| ![original](https://i.imgur.com/KmsyElb.png) | ![Fragment1Debug_2020-06-13-20-08-45-096](https://i.imgur.com/XgsdJxm.png) |

**Shape Study**

| Tracing dominating lines               | Breaking them down                     | Iterations                                     |
| -------------------------------------- | -------------------------------------- | ---------------------------------------------- |
| ![01](https://i.imgur.com/ybIENoQ.png) | ![02](https://i.imgur.com/g9HRzNN.png) | ![iterations](https://i.imgur.com/w71F9jV.gif) |

Shape consists of 3 dominant lines: top, middle and bottom. Top and bottom lines are sampled with the same interval (linear), whereas the mid line is sampled in a skewed manner. I have tried couple of functions to recreate the same amount of skewness, and I found **cubic function** `powf(x,3)` to be the closest, but it is not the same.

3 main lines are defined as `ofPolyline`, since it has a handy function to get a point at a percentage.

3 points can be sampled from polyline as:

```c++
vector < ofPoint > ofApp::CreateArrow(ofPolyline top, ofPolyline mid, ofPolyline bottom, float percentage ){
    vector < ofPoint > points;
    points.push_back(top.getPointAtPercent(percentage));
    points.push_back(mid.getPointAtPercent(powf(percentage, 3)));
    points.push_back(bottom.getPointAtPercent(percentage));
    return points;
} 
```

### Silkscreen prints -Bridget Riley

| Original                                     | Attempts                                     |
| -------------------------------------------- | -------------------------------------------- |
| ![original](https://i.imgur.com/TLmtIYo.jpg) | ![attempts](https://i.imgur.com/dpEdQZ1.gif) |

I tried to apply distortion to all the variables I can think of but could not find a way to distort the grid similarly.

I created the grid using polar coordinates instead of the cartesian to shape it circularly.  It is written as a fragment shader and code can be found at: https://www.shadertoy.com/view/tlscWM

Bonus distortion effect:

![Bonus](https://i.imgur.com/33tGU44.gif)