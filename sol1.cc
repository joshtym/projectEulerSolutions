#include <iostream>

int getSumOfThreeAndFiveMultiples(int);

int main(int argc, char** argv)
{
   std::cout << getSumOfThreeAndFiveMultiples(1000) << std::endl;
   return 0;
}

// This can be written as a recursive function
int getSumOfThreeAndFiveMultiples(int upperBound)
{
   auto sum = 0;
   for (auto i = 0; i < upperBound; ++i)
      sum += (i%5 == 0 || i %3 == 0) ? i : 0;
      
   return sum;
}