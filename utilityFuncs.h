#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <memory>

// Use of the seive for finding primes up to a number (needs to be adjusted as it does not work for large numbers)
// Note that this only works for the set of integers and is good enough
// TODO: Optimize this
std::vector<int> getNumberedPrimes(int size)
{
   long double sqrtOfNumber = sqrt(INT_MAX);
   std::vector<int> primes = {2};

   for (int i = 3; i <= INT_MAX; ++i)
   {
      if (primes.size() == size)
         break;

      if (std::all_of(primes.begin(), primes.end(), [&](int prime){return i%prime != 0;}))
         primes.push_back(i);
   }

   return primes;
}

// Use recursive method to determine prime factors by starting from the base prime of 2
std::vector<long long int> getPrimeFactors(long long int number, int startCheckNumber)
{
   std::vector<long long int> primeFactors;

   // Anything less than 2 will do weird things to this function
   if (startCheckNumber < 2)
      return primeFactors;

   while (number % startCheckNumber != 0)
      ++startCheckNumber;

   primeFactors.push_back(startCheckNumber);

   if (number == startCheckNumber)
      return primeFactors;

   while (number % startCheckNumber == 0)
      number /= startCheckNumber;

   std::vector<long long int> primeFactorsOfFactor = getPrimeFactors(number, startCheckNumber + 1);
   primeFactors.insert(primeFactors.end(), primeFactorsOfFactor.begin(), primeFactorsOfFactor.end());

   return primeFactors;
}

// Function to determine if a number is a palindrome
bool isNumberPalindrome(int number)
{
   auto numberAsString = std::to_string(number);
   auto startIndex = 0;
   auto endIndex = numberAsString.length() - 1;
   
   while(startIndex < endIndex)
      if (numberAsString[startIndex++] != numberAsString[endIndex--])
         return false;
      
   return true;
}

// TODO: Remove containered prime function
std::unique_ptr<bool[]> seiveUpToNumber(unsigned int maxNumber)
{
   std::unique_ptr<bool[]> primes = std::make_unique<bool[]>(maxNumber + 1);
   double sqrtOfNumber = sqrt(maxNumber);

   primes[0] = false;
   primes[1] = false;

   for (unsigned int i = 2; i <= maxNumber; ++i)
      primes[i] = true;

   for (unsigned int i = 2; i <= sqrtOfNumber; ++i)
   {
      if (!primes[i])
         continue;
      
      for (unsigned int j = i + i; j <= maxNumber; j += i)
         primes[j] = false;
   }

   return primes;
}

// Utility function to get all the primes up to a number (this function only works for unsigned max int)
std::vector<unsigned int> calculateSeiveUpToNumber(unsigned int maxNumber)
{
   std::vector<unsigned int> primes;
   std::unique_ptr<bool[]> primeIndicators = seiveUpToNumber(maxNumber);

   for (unsigned int i = 0; i <= maxNumber; ++i)
      if (primeIndicators[i])
         primes.push_back(i);

   return primes;
}

// Finalized solution involving the whole vector of numbers
std::string addVectorOfStringNumbers(std::vector<std::string> allNumbers)
{
   int carryOver = 0;
   char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
   auto largestElement = *(std::max_element(allNumbers.begin(), allNumbers.end(), [](std::string numOne, std::string numTwo) 
   {
      return numOne.length() < numTwo.length();
   }));
   
   int maxLength = largestElement.length();
   std::string sum = "";

   for (int i = 0; i < maxLength; ++i)
   {
      int numericSum = carryOver;
      for (int j = 0; j < allNumbers.size(); ++j)
      {
         // The character numeric digits are converted to int as follows:
         // '0' = 48, '1' = 49, '2' = 50, etc. So, we minus 48 from the numeric sum on conversion
         char digit = i < allNumbers[j].length() ? allNumbers[j][allNumbers[j].length() - 1 - i] : '0';
         numericSum += (int)digit - 48;
      }

      carryOver = numericSum / 10;
      numericSum = numericSum % 10;
      sum = numbers[numericSum] + sum;
   }

   while (carryOver != 0)
   {
      int val = carryOver % 10;
      carryOver = carryOver / 10;
      sum = numbers[val] + sum;
   }

   return sum;
}

std::vector<int> getProperDivisors(int number)
{
   std::vector<int> divisors = {1};
   for (int i = 2; i <= sqrt(number); ++i)
   {
      if (number % i == 0)
      {
         divisors.push_back(i);
         if (i != sqrt(number))
            divisors.push_back(number / i);
      }
   }
   return divisors;
}

int getSumOfDivisors(int sumOfDivisorsArray[], int number, int sizeOfArray)
{
   if (number < sizeOfArray && sumOfDivisorsArray[number] != -1)
      return number;
   
   std::vector<int> divisors = getProperDivisors(number);
   int sum = 0;

   for (int j = 0; j < divisors.size(); ++j)
      sum += divisors[j];

   if (number < sizeOfArray)
      sumOfDivisorsArray[number] = sum;

   return sum;
}

// Solution one involved adding two numbers the whole way through
std::string addTwoStringNumbers(std::string numOne, std::string numTwo)
{
   bool carryOver = false;
   char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
   int maxLength = std::max(numOne.length(), numTwo.length());
   std::string sum = "";

   for (int i = 0; i < maxLength; ++i)
   {
      char digitOne = i < numOne.length() ? numOne[numOne.length() - 1 - i] : '0';
      char digitTwo = i < numTwo.length() ? numTwo[numTwo.length() - 1 - i] : '0';
      int numericSum = 0 + carryOver;
      for (int j = 0; j < 10; ++j)
      {
         if (digitOne == numbers[j])
            numericSum += j;
         if (digitTwo == numbers[j])
            numericSum += j;
      }

      carryOver = numericSum >= 10;
      numericSum = carryOver ? numericSum - 10 : numericSum;
      sum = numbers[numericSum] + sum;
   }

   if (carryOver)
      sum = '1' + sum;

   return sum;
}

bool isPrime(int number)
{
   if (number < 2)
      return false;
   
   if (number == 2)
      return true;

   for (int i = 2; i <= sqrt(number); ++i)
      if (number % i == 0)
         return false;

   return true;
}