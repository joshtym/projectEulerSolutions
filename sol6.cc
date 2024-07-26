#include <iostream>
#include <cmath>

long long int differenceBetweenSumOfSquaresAndSquareOfSumsOfFirstNNumbers(int);

int main(int argc, char** argv)
{
   std::cout << differenceBetweenSumOfSquaresAndSquareOfSumsOfFirstNNumbers(100) << std::endl;
   return 0;
}

// Solution for EULER #6
long long int differenceBetweenSumOfSquaresAndSquareOfSumsOfFirstNNumbers(int upperBound)
{
   auto sumOfSquares = 0;
   auto sumOfNums = 0;
   for (auto i = 1; i <= upperBound; ++i)
   {
      sumOfSquares += std::pow(i, 2);
      sumOfNums += i;
   }

   return std::pow(sumOfNums,2) - sumOfSquares;
}
