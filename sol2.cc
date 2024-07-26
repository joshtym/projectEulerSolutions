#include <iostream>

long long int getSumOfEvenFibNumsNotExceedingNum(int);

int main(int argc, char** argv)
{
   std::cout << getSumOfEvenFibNumsNotExceedingNum(4000000) << std::endl;
   return 0;
}

long long int getSumOfEvenFibNumsNotExceedingNum(int upperLimit)
{
   long long int sum = 0;
   int fibNumOne = 1;
   int fibNumTwo = 2;
	
   while (true)
   {
      if (fibNumOne <= upperLimit)
         sum += fibNumOne % 2 == 0 ? fibNumOne : 0;
      else
         break;
		
      if (fibNumTwo <= upperLimit)
         sum += fibNumTwo % 2 == 0 ? fibNumTwo : 0;
      else
         break;
		
      fibNumOne = fibNumOne + fibNumTwo;
      fibNumTwo = fibNumOne + fibNumTwo;
   }
   
   return sum;
}
