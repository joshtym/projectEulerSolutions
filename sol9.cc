#include <iostream>
#include <cmath>

void determinePythagoreanTriplet(double&, double&, double&);

int main(int argc, char** argv)
{
   double a, b, c;
   determinePythagoreanTriplet(a, b, c);
   std::cout << a << " " << b << " " << c << std::endl;
   std::cout << a * b * c << std::endl;
   return 0;
}

// Solution to EULER #9
void determinePythagoreanTriplet(double& a, double& b, double& c)
{
   a = 1.0;
   auto foundTriplet = false;

   auto getCVal = [] (int i, int j)
   {
      return sqrt(pow(i, 2) + pow(j, 2));
   };

   while (true)
   {
      b = a + 1;
      while (true)
      {
         c = getCVal(a, b);

         if (a + b + c > 1000)
            break;

         if (c == floor(c) && c == ceil(c) && a + b + c == 1000)
            return;
         b++;
      }
      a++;
   }
}