// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include "desaturate.h"
using graphics::Color;

void Desaturate(graphics::Image& image) {
  // Your code here to desaturate the image
  // After reading the Image class we have some useful functions built
  // into the class

  int width = image.GetWidth();
  int height = image.GetHeight();
  const int rgbAverage = 3;

  // Loop through every pixel
  for (short int x = 0; x < width; x++) {
    for (short int y = 0; y < height; y++) {
      // I use the class color and ger the image Color of the current
      // pixel
      Color color = image.GetColor(x, y);
      // Then I average the colors to get the grey Scale
      int greyScale = (color.Red() + color.Blue() + color.Green()) / rgbAverage;
      // Finally I set the Image colors, if i used the class i would
      // jave to change the class and then the color. Seemed like one
      // extra step
      image.SetRed(x, y, greyScale);
      image.SetGreen(x, y, greyScale);
      image.SetBlue(x, y, greyScale);
    }
  }
}
