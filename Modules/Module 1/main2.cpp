#include <iostream>
#define PI 3.1415926535

using namespace std;

class Cylinder
{
private:
  int radius;
  int height;
  double vol;
public:
  void init(int r, int h)
  {
    radius = r;
    height = h;
  }
  double getVolume()
  {
    vol = PI * radius * radius * height;
    return vol;
  }
};

int main()
{
  Cylinder c;
  c.init(10,20);
  double v = c.getVolume();
  cout << "The volume is: " << v << endl;
}
