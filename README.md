# Wavelet-CppWForms
Wavelet tools for 1D and 2D wavelet transform.

## Screenshots:

### Wavelet Selection
![Wavelet Selection](https://github.com/Jens-Kluge/Wavelet-CppWForms/blob/master/Screenshots/WaveletSelection.GIF)

The slider can be used to change the wavelet index from 0 to 1023 which will change the wavelet order and position. 

### 2D Wavelet Transform
![2D Wavelet Transform](https://github.com/Jens-Kluge/Wavelet-CppWForms/blob/master/Screenshots/2D%20Wavelet%20Transform.GIF)

For better visibilty I have applied a dynamic range compression with the function *"sign(x)*log(1+abs(x))"* so the picture is not dominated by very few large magnitude values. I have also set values with small magnitude to white color, which gives a better contrast than a grey background. For the remaining values I have applied a color coding. Thereby I avoid that large negative or positive values will also be mapped to white and disappear.

The wavelet transformation is a complete transformation in the sense that it decomposes the picture until the remaining length reaches 4. The decomposition is not performed simultaneously for the 2 coordinate directions, as if often done, but it is performed independently for the two directions. Therefore, the aspect ratio of the rectangles changes by a factor of 2 in the x or in the y direction. The low index wavelets, which capture the smooth variations, correspond to the upper left corner of the image. As expected, the picture is "sparse" and only a few values are significantly different from zero.

### 1D Wavelet Transform
![1D Wavelet Transform](https://github.com/Jens-Kluge/Wavelet-CppWForms/blob/master/Screenshots/1D%20Wavelet%20Transform.GIF)

### Excel Import
![Excel Import](https://github.com/Jens-Kluge/Wavelet-CppWForms/blob/master/Screenshots/Excel%20Import.GIF)

Set of 33.351 wind speed measurements for 40 m above ground level (AGL), zero-padded to the next power of 2. 
