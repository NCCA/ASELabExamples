#include <iostream>
#include <cstdlib>
#include <cmath>

int main()
{
  std::cout << "# enter a radius >";
  std::cout << "#X #Y\n";
  double radius;
  std::cin>>radius;
  for(double t=0.0; t<2*M_PI; t+=0.1)
  {
    auto x=radius*cos(t);
    auto y=radius*sin(t);
    std::cout<<x<<" "<<y<<'\n';
  }
  return EXIT_SUCCESS;
}
