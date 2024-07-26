#include <iostream>
#include <string>

int getSumOfCuriousNumbers();
int factorial(int);

int factorialNumbers[10];

int main(int argc, char** argv)
{
   std::cout << getSumOfCuriousNumbers() << std::endl;
   return 0;
}

int getSumOfCuriousNumbers()
{
   int maxNumber = factorial(9) * 6;
   int sum = 0;

   for (int i = 10; i <= maxNumber; ++i)
   {
      std::string numAsString = std::to_string(i);

      int tmpSum = 0;
      for (int j = 0; j < numAsString.length(); ++j)
         tmpSum += factorial((int)numAsString[j] - 48);
      
      if (tmpSum == i)
         sum += i;
   }

   return sum;
}

int factorial(int number)
{
   if (number < 0)
      return -1;
   
   if (factorialNumbers[number] != 0)
      return factorialNumbers[number];
      
   if (number < 10)
   {
      factorialNumbers[number] = number == 0 ? 1 : number * factorial(number - 1);
      return factorialNumbers[number];
   }
   else
      return number * factorial(number - 1);
}