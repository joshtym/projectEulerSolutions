#include <iostream>
#include <algorithm>
#include <vector>

struct Fraction
{
   Fraction(long long int num, long long int denom) : numerator{num}, denominator{denom} {}

   long long int numerator;
   long long int denominator;

   bool operator==(const Fraction& cmpFraction)
   {
      return numerator== cmpFraction.numerator && denominator == cmpFraction.denominator;
   }

   bool operator*=(const Fraction& fraction)
   {
      numerator *= fraction.numerator;
      denominator *= fraction.denominator;
   }

   void reduceFraction()
   {
      long long int gcd;

      for (long long int i = 1; i <= std::min(numerator, denominator); ++i)
         if (numerator % i == 0 && denominator % i == 0)
            gcd = i;
      
      numerator /= gcd;
      denominator /= gcd;
   }
};

int getSumOfNonTrivialCuriousFractionsDenom();
bool isCuriousFraction(Fraction, int);
Fraction multiplyFractions(std::vector<Fraction>);
Fraction addFractions(std::vector<Fraction>);

int main(int argc, char** argv)
{
   std::cout << getSumOfNonTrivialCuriousFractionsDenom() << std::endl;
   return 0;
}

int getSumOfNonTrivialCuriousFractionsDenom()
{
   std::vector<Fraction> curiousFractions;

   for (int i = 10; i <= 99; ++i)
      for (int j = i + 1; j <= 99; ++j)
      {
         if (i % 10 == 0 && j % 10 == 0)
            continue;
         
         Fraction fraction(i, j);

         for (int k = 0; k < 4; ++k)
            if (isCuriousFraction(fraction, k))
            {
               curiousFractions.push_back(fraction);
               break;
            }
      }
   
   Fraction summedFraction = multiplyFractions(curiousFractions);

   return summedFraction.denominator;
}

bool isCuriousFraction(Fraction fraction, int option)
{
   int tmpNumerator = option <= 1 ? fraction.numerator / 10 : fraction.numerator % 10;
   int tmpDenominator = option % 2 == 0 ? fraction.denominator / 10 : fraction.denominator % 10;

   if (tmpNumerator != tmpDenominator)
      return false;
   
   Fraction tmpFraction(option <= 1 ? fraction.numerator % 10 : fraction.numerator / 10,
                        option % 2 == 0 ? fraction.denominator % 10 : fraction.denominator / 10);
   
   fraction.reduceFraction();
   tmpFraction.reduceFraction();

   return fraction == tmpFraction;
}

Fraction multiplyFractions(std::vector<Fraction> fractions)
{
   if (fractions.size() == 0)
      return Fraction(0, 1);
   
   Fraction productFraction = Fraction(1, 1);

   for (int i = 0; i < fractions.size(); ++i)
   {
      fractions[i].reduceFraction();
      productFraction.numerator *= fractions[i].numerator;
      productFraction.denominator *= fractions[i].denominator;
      productFraction.reduceFraction();
   }

   return productFraction;
}

Fraction addFractions(std::vector<Fraction> fractions)
{
   if (fractions.size() == 0)
      return Fraction(0, 1);

   for (int i = 0; i < fractions.size(); ++i)
      fractions[i].reduceFraction();
   
   Fraction summedFraction = fractions[0];

   for (int i = 1; i < fractions.size(); ++i)
   {
      summedFraction.numerator = summedFraction.numerator * fractions[i].denominator + fractions[i].numerator * summedFraction.denominator;
      summedFraction.denominator = summedFraction.denominator * fractions[i].denominator;
      summedFraction.reduceFraction();
   }

   return summedFraction;
}