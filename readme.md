## Week 1 - Vera Molnar 

### Carrés en 2 positions 

![01](./Week1-Vera-Molnar/Carres-en-2-positions/media/01.gif)

### Computer-rosace-series

![01](./Week1-Vera-Molnar/Computer-rosace-series/media/01.png)

### de la serie 100 carres

![01](./Week1-Vera-Molnar/de-la-serie-100-carres/media/01.png)



### du cycle inclinaisions

![01](./Week1-Vera-Molnar/du-cycle-inclinaisions/media/01.png)



### Horizontales

![01](./Week1-Vera-Molnar/Horizontales/media/01.gif)



### Sainte-Victoire On Line

![01](./Week1-Vera-Molnar/Sainte-Victoire-On-Line/media/01.gif)

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



| 01                                                 | 02                                                           | 03                                                           |
| -------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![01](./Week2-JohnWhitney/Matrix-III/media/01.gif) | ![02](./Week2-JohnWhitney/Matrix-III/media/02.gif)           | ![03](./Week2-JohnWhitney/Matrix-III/media/03.gif)           |
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

