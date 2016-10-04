#include <iostream>
#include <cstdlib>
#include <cmath>

int main()
{
  double amp;
  double freq;
  std::cout<<"# enter the frequency >";
  std::cin>>freq;
  std::cout<<"# enter the amplitude >";
  std::cin>>amp;
  
  for(double x=0.0; x<6.0; x+=0.01)
  {
    std::cout<<x<<' '<<amp*sin(freq*M_PI*x)<<' '<<amp*cos(freq*M_PI*x)<<'\n';
  }
  return EXIT_SUCCESS;
}