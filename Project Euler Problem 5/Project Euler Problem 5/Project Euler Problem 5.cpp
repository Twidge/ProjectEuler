// Project Euler Problem 5.cpp
//
// What is the smallest positive number divisible by all the numbers from 1 to 20?

#include "stdafx.h"
#include <iostream>
#include <limits>
#include <C:/Users/Matthew/Documents/GitHub/ProjectEuler/CommonFunctions.h>

const unsigned int G_MAX_DIVISOR = 20;

int _tmain(int argc, _TCHAR* argv[])
{
	uint64_t t_result = 1;
	std::vector<uint64_t> t_primeFactorsWithMultiplicities = std::vector<uint64_t>();

	// For each integer...
	for (uint64_t l_nextNumber = 2; l_nextNumber <= G_MAX_DIVISOR; l_nextNumber++)
	{
		// Find all prime factors with multiplicities
		std::vector<uint64_t> t_smallerPrimeFactorsWithMultiplicities = FindAllPrimeFactorsWithMultiplicities(l_nextNumber);

		// For each prime factor, if it appears with higher multiplicity than we have seen so far, add as many copies to the list of
		// prime factors with multiplicities as will make up the difference

		for (unsigned int l_nextPrimeFactor = 0; l_nextPrimeFactor < t_smallerPrimeFactorsWithMultiplicities.size();
			l_nextPrimeFactor++)
		{
			// The number of times the prime appears in t_primeFactorsWithMultiplicities
			int t_primeMultiplicity = 0;

			// The number of times the prime appears in t_smallerPrimeFactorsWithMultiplicities
			int t_smallerPrimeMultiplicity = 0;

			// Find how many times the next prime appears in t_smallerPrime...

			for (unsigned int l_nextFactor = 0; l_nextFactor < t_smallerPrimeFactorsWithMultiplicities.size(); l_nextFactor++)
			{
				if (t_smallerPrimeFactorsWithMultiplicities[l_nextFactor] == t_smallerPrimeFactorsWithMultiplicities[l_nextPrimeFactor])
				{
					t_smallerPrimeMultiplicity++;
				}
			}

			// Check how many times the prime we've just been looking at appears in t_primeFactors...

			for (unsigned int l_nextFactor = 0; l_nextFactor < t_primeFactorsWithMultiplicities.size(); l_nextFactor++)
			{
				if (t_primeFactorsWithMultiplicities[l_nextFactor] == t_smallerPrimeFactorsWithMultiplicities[l_nextPrimeFactor])
				{
					t_primeMultiplicity++;
				}
			}

			for (int l_copiesToBeAdded = 0; l_copiesToBeAdded < t_smallerPrimeMultiplicity - t_primeMultiplicity;
				l_copiesToBeAdded++)
			{
				t_primeFactorsWithMultiplicities.push_back(t_smallerPrimeFactorsWithMultiplicities[l_nextPrimeFactor]);
			}
		}

		std::cout << "Done for " << l_nextNumber << ".\n";
	}

	// Multiply all the factors in t_primeFactors...

	for (unsigned int l_nextIndex = 0; l_nextIndex < t_primeFactorsWithMultiplicities.size(); l_nextIndex++)
	{
		t_result *= t_primeFactorsWithMultiplicities[l_nextIndex];
	}

	std::cout << "Largest number divisible by every number from 1 to " << G_MAX_DIVISOR << " is: " << t_result;
	std::cin.get();

	return 0;
}