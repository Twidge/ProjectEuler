// Project Euler Problem 10
//
// Find the sum of the primes below two million

#include "stdafx.h"
#include <iostream>
#include <C:/Users/Matthew/Documents/GitHub/ProjectEuler/CommonFunctions.h>

const uint64_t G_UPPER_BOUND = 2000000;

int _tmain(int argc, _TCHAR* argv[])
{
	uint64_t t_result = 0;

	// This is the first problem to actually run in non-trivial time on my laptop - takes a few seconds. Not sure how to optimise.

	for (uint64_t l_nextNumber = 2; l_nextNumber < G_UPPER_BOUND; l_nextNumber++)
	{
		if (IsPrime(l_nextNumber))
		{
			t_result += l_nextNumber;
		}
	}

	std::cout << "The sum of all the primes below " << G_UPPER_BOUND << " is: " << t_result;
	std::cin.get();

	return 0;
}

