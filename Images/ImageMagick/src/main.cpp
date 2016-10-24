#include "Image.h"
#include <cstdlib>
#include <iostream>
int main()
{
  std::cout<<"Need to write an Image Class\n";
  Image image(200,200);
  image.setBackground(255,0,255);
  image.save("test.png");
  return EXIT_SUCCESS;
}
