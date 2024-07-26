#include <iostream>

int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeapYear(int);
int getNumOfSundaysOnFirstsBetweenYears(int startYear, int endYear);

int main(int argc, char** argv)
{
   std::cout << getNumOfSundaysOnFirstsBetweenYears(1901, 2000) << std::endl;
   return 0;
}

int getNumOfSundaysOnFirstsBetweenYears(int startYear, int endYear)
{
   int firstOfMonthModulo = 0;
   int currYear = 1899;
   int numOfSundaysOnFirst = 0;

   while (startYear < currYear)
      firstOfMonthModulo = (firstOfMonthModulo - 365 - isLeapYear(--currYear)) % 7;

   while (startYear > currYear)
      firstOfMonthModulo = (firstOfMonthModulo + 365 + isLeapYear(currYear++)) % 7;

   for (int i = startYear; i <= endYear; ++i)
   {
      for (int j = 0; j < 12; ++j)
      {
         numOfSundaysOnFirst += firstOfMonthModulo == 0;
         firstOfMonthModulo = (firstOfMonthModulo + daysPerMonth[j] + (j == 1 && isLeapYear(currYear))) % 7;
      }
   }

   return numOfSundaysOnFirst;
}

bool isLeapYear(int year)
{
   return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}