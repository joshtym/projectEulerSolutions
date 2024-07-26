#ifndef PRIMES_H
#define PRIMES_H

#include <vector>

class Primes
{
    public:
        Primes();
        Primes(unsigned long long int);
        
        void initializeToVal(unsigned long long int);
        bool isPrime(unsigned long long int);
        unsigned long long int getNumberedPrime(unsigned long long int);
        unsigned long long int getNumberOfPrimes(unsigned long long int);
        std::vector<unsigned long long int> getContainerOfPrimes();
        std::vector<unsigned long long int> getPrimeFactors(unsigned long long int);
    private:
        std::vector<bool> primes;
};

#endif