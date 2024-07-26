#include <iostream>
#include <string>

std::string doubleStringNumber(std::string);

int main(int argc, char** argv)
{
   std::string number = "2";
   for (int i = 1; i < 1000; ++i)
      number = doubleStringNumber(number);

   int sum = 0;

   for (int i = 0; i < number.length(); ++i)
      sum += ((int)number[i]) - 48;

   std::cout << sum << std::endl;
   return 0;
}

std::string doubleStringNumber(std::string number)
{
   char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
   std::string returnedNumber = "";
   int carryOver = 0;

   for (int i = 0; i < number.length(); ++i)
   {
      int valToDouble = (int)(number[number.length() - 1 - i]) - 48;
      valToDouble *= 2;
      valToDouble += carryOver;
      carryOver = valToDouble / 10;
      valToDouble %= 10;
      returnedNumber = numbers[valToDouble] + returnedNumber;
   }

   while (carryOver != 0)
   {
      returnedNumber = numbers[carryOver % 10] + returnedNumber;
      carryOver /= 10;
   }

   return returnedNumber;
}