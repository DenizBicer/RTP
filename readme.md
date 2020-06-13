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

## Week 1 - Vera Molnar 

| Carrés en 2 positions                                        | Computer-rosace-series                                       | de la serie 100 carres                                       |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![01](./Week1-Vera-Molnar/Carres-en-2-positions/media/01.gif) | ![01](./Week1-Vera-Molnar/Computer-rosace-series/media/01.png) | ![01](./Week1-Vera-Molnar/de-la-serie-100-carres/media/01.png) |
| du cycle inclinaisions                                       | Horizontales                                                 | Sainte-Victoire On Line                                      |
| ![01](./Week1-Vera-Molnar/du-cycle-inclinaisions/media/01.png) | ![01](./Week1-Vera-Molnar/Horizontales/media/01.gif)         | ![01](./Week1-Vera-Molnar/Sainte-Victoire-On-Line/media/01.gif) |



## Week 2 - John Whitney

### Harmony



![harmony original](./Week2-JohnWhitney/Harmony/media/harmony_original.png)

| 01 -  Wrong map range                                                                          | 02 - Wrong variable in sin                                                  | 03 -  Worked!                                                                                      |
| :--------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------- |
| ![01](./Week2-JohnWhitney/Harmony/media/01.gif)                                                | ![02](./Week2-JohnWhitney/Harmony/media/02.gif)                             | ![03](./Week2-JohnWhitney/Harmony/media/03.gif)                                                    |
| ```float x = ofMap(sin(time*frequency )*amplitude, -amplitude, amplitude, 0, ofGetWidth());``` | ` float x = ofMap(sin(time * M_PI * 2 / period ), -1, 1, 0, ofGetWidth());` | `    float x = ofMap(sin(y * frequency * M_PI * 2 / period ) *amplitude, -1, 1, 0, ofGetWidth());` |
| ` -amplitude, amplitude` range should have been `-1, 1`                                        | instead of `time` use `y` value.                                            |                                                                                                    |

### Lissajous-curve

Recreating the below curve table:

![curve-table](./Week2-JohnWhitney/Lissajous-curve/media/curve-table.gif)

Equation: ![equation](./Week2-JohnWhitney/Lissajous-curve/media/equation.png)

The table is changing two parameters **a** and **b**.

Rows are increasing the **a** value from top to down. Range is [1,7]

Columns are increasing the **b** value from left to right . Range is [1,7]



| 01 - no grid                                            | 02 - wrong spacing at grid                              | 03 - worked!                                            |
| ------------------------------------------------------- | ------------------------------------------------------- | ------------------------------------------------------- |
| ![01](./Week2-JohnWhitney/Lissajous-curve/media/01.gif) | ![02](./Week2-JohnWhitney/Lissajous-curve/media/02.gif) | ![03](./Week2-JohnWhitney/Lissajous-curve/media/03.gif) |

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



| 01                                                 | 02                                                                                                                                                                | 03                                                                                                                  |
| -------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------- |
| ![01](./Week2-JohnWhitney/Matrix-III/media/01.gif) | ![02](./Week2-JohnWhitney/Matrix-III/media/02.gif)                                                                                                                | ![03](./Week2-JohnWhitney/Matrix-III/media/03.gif)                                                                  |
|                                                    | removing the **i** from equation made them align too much. Also they should have collapsed in the middle but because of `+ M_PI * 0.5`  it collapsed on the side. | This version is closer to the original but they align to a lign before collapsing instead of coming from all sides. |



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

| ![study1](./Week2-JohnWhitney/Catalog/media/study1.png)       | ![study2](./Week2-JohnWhitney/Catalog/media/study2.png)                       |
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

![shape](./Week2-JohnWhitney/Catalog/media/shape.png)

Code details:

- in order to move the shape origin to the middle every center point is offsetted by **(290,120)**. 
- **arc** draws the path in *clockwise* and **arcNegative** in *counter-clockwise*
- whole shape is drawn in *clockwise* 
- Tried different **PolyWindingMode**s and decided on using *OF_POLY_WINDING_POSITIVE* (2) which closed the path without artefacts.

**Iterations**

| 01                                                                                                                          | 02                                                               |
| --------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------- |
| ![01](./Week2-JohnWhitney/Catalog/media/01.png)                                                                             | ![02](./Week2-JohnWhitney/Catalog/media/02.gif)                  |
| The position of the arcs are correct but couldn't figure out the rotation yet. The pivot was not set properly for rotation. | The **mouseX** position is used to change the size of the shape. |

**02**

- used  ` ofEnableBlendMode(OF_BLENDMODE_ADD)` to make the overlapping regions emit more light
- used a **fragment shader** to color parts of the ofPath 



## Week 3

### Morisawa

| Original Work                                                | **Reproduction**                                             |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![morisawa2](./Week3-MurielCooper-JohnMaeda/morisawa/media/morisawa2.jpg) | ![devImg2020-06-10-19-07-13-086](./Week3-MurielCooper-JohnMaeda/morisawa/bin/data/images/devImgs/devImg2020-06-10-19-07-13-086.jpg) |



Used the [FZGonta-kana](http://zone108.main.jp/font/fz-gonta-kana.html) font. Unzipping the font under MacOS was not trivial. 

I found this command from [here](https://github.com/CocoaPods/CocoaPods/issues/7711) to unzip the font file that has japanese characters as a name:

`$ ditto -V -x -k --sequesterRsrc --rsrc FILENAME.ZIP DESTINATIONDIRECTORY`



[fix screenshot colors](https://forum.openframeworks.cc/t/ofimage-grabscreen-distorting-colours/34318/6): line 1917 of “ofGLRenderer.cpp”:

`auto pixelFormat = OF_PIXELS_RGBA; `



I suppose, becuase of the difference at the font the reproduction looks darker.

## Week4-Anni-Albers-et-al

### Blaze 1 - Bridget Riley

| Original                                                            | Recreation                                                                                                                |
| ------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------- |
| ![original](./Week4-Anni-Albers-et-al/Blaze1/bin/data/original.jpg) | ![Blaze1Debug_2020-06-12-22-06-24-703](./Week4-Anni-Albers-et-al/Blaze1/bin/data/Blaze1Debug_2020-06-12-22-06-24-703.png) |



**Shape Study**

| Extracting the building blocks                          | seperating circles                                      | finding points to draw an arrow between circles         |
| ------------------------------------------------------- | ------------------------------------------------------- | ------------------------------------------------------- |
| ![01](./Week4-Anni-Albers-et-al/Blaze1/bin/data/01.png) | ![02](./Week4-Anni-Albers-et-al/Blaze1/bin/data/02.png) | ![03](./Week4-Anni-Albers-et-al/Blaze1/bin/data/03.png) |

| Iterations                                                              | Noise on circles                                              |
| ----------------------------------------------------------------------- | ------------------------------------------------------------- |
| ![iterations](./Week4-Anni-Albers-et-al/Blaze1/bin/data/iterations.gif) | ![noise](./Week4-Anni-Albers-et-al/Blaze1/bin/data/noise.gif) |



**Experiments** 



| Noise by sampled degree (thickness)                       | Noise by cicle (thickness)                                |
| --------------------------------------------------------- | --------------------------------------------------------- |
| ![e01](./Week4-Anni-Albers-et-al/Blaze1/bin/data/e01.gif) | ![e02](./Week4-Anni-Albers-et-al/Blaze1/bin/data/e02.gif) |

|                                                           |                                                           |
| --------------------------------------------------------- | --------------------------------------------------------- |
| ![e03](./Week4-Anni-Albers-et-al/Blaze1/bin/data/e03.gif) | ![e04](./Week4-Anni-Albers-et-al/Blaze1/bin/data/e04.gif) |

| noise on sample degree                                    | noise on sample degree with a smaller range               | fix sample count and change sample degree                 |
| --------------------------------------------------------- | --------------------------------------------------------- | --------------------------------------------------------- |
| ![e05](./Week4-Anni-Albers-et-al/Blaze1/bin/data/e05.gif) | ![e06](./Week4-Anni-Albers-et-al/Blaze1/bin/data/e06.gif) | ![eo7](./Week4-Anni-Albers-et-al/Blaze1/bin/data/eo7.gif) |

