#include <cmath>
#include <algorithm>
#include "Primes.h"

Primes::Primes()
{
    primes.clear();
    initializeToVal(1000000);
}

Primes::Primes(unsigned long long int size)
{
    primes.clear();
    initializeToVal(size);
}

void Primes::initializeToVal(unsigned long long int value)
{
    unsigned long long int containerSize = value + 1;
    
    if (primes.size() >= containerSize)
        return;
    
    if (!primes.capacity() >= containerSize)
    {
        unsigned long long int reserveSize = primes.size() * 2;
        reserveSize = std::max(reserveSize, containerSize);
        primes.reserve(reserveSize);
    }
    
    for (unsigned long long int i = 0; i < containerSize; ++i)
    {
        if (i == primes.size())
            primes.push_back(true);
        else
            primes[i] = true;
    }
    
    for (unsigned long long int i = 0; i <= sqrt(containerSize); ++i)
    {
        if (i == 0 || i == 1)
        {
            primes[i] = false;
            continue;
        }
        
        if (!primes[i])
            continue;
        
        for (unsigned long long int j = i + i; j < containerSize; j += i)
            primes[j] = false;
    }
}

bool Primes::isPrime(unsigned long long int val)
{
    if (val >= primes.size())
        initializeToVal(val);
        
    return primes[val];
}

unsigned long long int Primes::getNumberedPrime(unsigned long long int value)
{
    unsigned long long int indexToStartAt = 0;
    unsigned long long int primesAtIndex = 0;
    
    while(true)
    {
        unsigned long long int currNumOfPrimes = getNumberOfPrimes(indexToStartAt);
        
        if (currNumOfPrimes + primesAtIndex >= value)
            break;
            
        primesAtIndex += currNumOfPrimes;
        indexToStartAt = primes.size();
        initializeToVal(primes.size() * 2);
    }
    
    while(true)
    {
        if (indexToStartAt > primes.size())
            return -1;
        
        primesAtIndex += primes[indexToStartAt];
        
        if (primesAtIndex == value)
            return indexToStartAt;
        
        indexToStartAt++;
    }
    
    return -1;
}

unsigned long long int Primes::getNumberOfPrimes(unsigned long long int startingIndex = 0)
{
    if (startingIndex >= primes.size())
        return -1;
        
    unsigned long long int numOfPrimes = 0;
    
    for (unsigned long long int i = startingIndex; i < primes.size(); ++i)
        numOfPrimes += primes[i];
    
    return numOfPrimes;
}

std::vector<unsigned long long int> Primes::getContainerOfPrimes()
{
    std::vector<unsigned long long int> containerOfPrimes;
    
    for (unsigned long long int i = 0; i < primes.size(); ++i)
        if (primes[i])
            containerOfPrimes.push_back(i);
    
    return containerOfPrimes;
}

std::vector<unsigned long long int> Primes::getPrimeFactors(unsigned long long int value)
{
    if (value >= primes.size())
        initializeToVal(value);
        
    std::vector<unsigned long long int> primeFactors;
    
    unsigned long long int primeFactor = 2;
    
    while(true)
    {
        if (isPrime(value))
        {
            primeFactors.push_back(value);
            break;
        }
        
        if (value % primeFactor == 0)
        {
            while (value % primeFactor == 0)
            {
                primeFactors.push_back(primeFactor);
                value /= primeFactor;
            }
            
            if (value == 1)
                break;
            
            primeFactor++;
            
            while (!isPrime(primeFactor) || value % primeFactor != 0)
                primeFactor++;
        }
    }
    
    return primeFactors;
}