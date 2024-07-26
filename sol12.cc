#include <iostream>
#include <vector>
#include <cmath>

long long int getTriangleNumWith500Div();
int getNumOfDivisors(long long int);

int main(int argc, char** argv)
{
   std::cout << getTriangleNumWith500Div() << std::endl;
   return 0;
}

long long int getTriangleNumWith500Div()
{
   long long int triNumber = 0;
   long long int currNumber = 1;

   while (true)
   {
      triNumber += currNumber;
      if (getNumOfDivisors(triNumber) > 500)
         return triNumber;
      currNumber++;
   }
}

int getNumOfDivisors(long long int number)
{
   int divisors = 2;
   double sqrtOfNumber = sqrtl(number);

   for (int i = 2; i <= sqrtOfNumber; ++i)
      if (number % i == 0)
         divisors += (number / i != i) ? 2 : 1;
   
   return divisors;
}