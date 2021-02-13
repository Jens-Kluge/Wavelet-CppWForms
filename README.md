# Wavelet-CppWForms
Wavelet tools for 1D and 2D wavelet transform.

## Screenshots:

### Wavelet Selection
![Wavelet Selection](https://github.com/Jens-Kluge/Wavelet-CppWForms/blob/master/Screenshots/WaveletSelection.GIF)

The slider can be used to change the wavelet index from 0 to 1023 which will change the wavelet order and position. The order 0 zero has only two positions, the next order 2 has 4 positions, etc. until order 9, which has 512 positions and the wavelets of the smallest scale. You can play around with the slider to find out. 

### 2D Wavelet Transform
![2D Wavelet Transform](https://github.com/Jens-Kluge/Wavelet-CppWForms/blob/master/Screenshots/2D%20Wavelet%20Transform.GIF)

For better visibilty I have applied a dynamic range compression with the function *"sign(x)\*log(1+abs(x))"* so the picture is not dominated by very few large magnitude values. I have also set values with small magnitude to white color, which gives a better contrast than a grey background. For the remaining values I have applied a color coding. Thereby I avoid that large negative or positive values will also be mapped to white and disappear.

The wavelet transformation is a complete transformation in the sense that it decomposes the picture until the remaining length reaches 4. The decomposition is not performed simultaneously for the 2 coordinate directions, as is often done, but it is performed independently for the two directions. Therefore, the aspect ratio of the rectangles changes by a factor of 2 in the x or in the y direction. The low index wavelets, which capture the smooth variations, correspond to the upper left corner of the image. As expected, the picture is "sparse" and only a few values are significantly different from zero.

### 1D Wavelet Transform
![1D Wavelet Transform](https://github.com/Jens-Kluge/Wavelet-CppWForms/blob/master/Screenshots/1D%20Wavelet%20Transform.GIF)

The periodic variation of the sine signal is reflected in the wavelet coefficients of the various orders, which also vary periodically. The "undulation" reflects the change in phase between the wavelet and the sine functions: the overlap between the wavelet and the signal changes depending on the wavelet position. 

### Excel Import
![Excel Import](https://github.com/Jens-Kluge/Wavelet-CppWForms/blob/master/Screenshots/Excel%20Import.GIF)

Set of 33.351 wind speed measurements for 40 m above ground level (AGL), zero-padded to the next power of 2. A decomposition of the signal into different levels (upcoming) will allow to differentiate the daily/seasonal variations of the wind speed from the random fluctuations. 

You can click on the button next to the range textfield to minimize the control to the size of the textbox and button. For selection you can click on the first cell and then into the text field to activate the control. As long as the control is active the displayed cell range is adjusted to the current selection. You can also click on the extend button to extend the range to the end. Data Import works via direct assignment to an object array as opoposed to looping through the spreadsheet rows. This method is reasonably fast and can handle large data sets with over 32.000 rows. 
