// Name: Joseph Eggers
// CWID: 885939488
// Enail: joseph.eggers@csu.fullerton.edu

#include "mirror.h"

#include <algorithm>
#include <vector>
using std::vector, std::reverse, graphics::Color;

void Mirror(graphics::Image& image) {
  // Your code here to mirror the image.
  // First thing is grab the height and the width for the bounds
  int width = image.GetWidth();
  int height = image.GetHeight();

  // Loop through every pixel
  for (short int y = 0; y < height; y++) {
    // Declare Vector here to be used throuhout the other forloops
    vector<Color> mirror;
    // Cycle line by line. grab the colors and push into mirror
    for (short int x = 0; x < width; x++) {
      Color color = image.GetColor(x, y);
      mirror.push_back(color);
    }
    // Reverese the line of colors
    reverse(mirror.begin(), mirror.end());
    // Loop throught the image again to swap the x row for the new colors
    for (short int x = 0; x < width; x++) {
      image.SetColor(x, y, mirror[x]);
    }
  }
}
