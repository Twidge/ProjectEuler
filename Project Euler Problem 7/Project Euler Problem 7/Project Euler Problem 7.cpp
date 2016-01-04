// Project Euler Problem 7
//
// Find the 10001st prime

#include "stdafx.h"
#include <iostream>
#include <C:/Users/Matthew/Documents/GitHub/ProjectEuler/CommonFunctions.h>

const uint64_t G_NTH_PRIME = 10001;

int _tmain(int argc, _TCHAR* argv[])
{
	uint64_t t_result = 0;
	uint64_t t_primeCounter = 0;

	// For each number, check if it is prime - stop when we have found the desired amount.

	for (uint64_t t_nextNumber = 2; t_nextNumber < UINT64_MAX; t_nextNumber++)
	{
		if (IsPrime(t_nextNumber))
		{
			t_primeCounter++;

			if (t_primeCounter == G_NTH_PRIME)
			{
				t_result = t_nextNumber;
				break;
			}
		}
	}

	std::cout << "Prime number " << G_NTH_PRIME << " is: " << t_result;

	std::cin.get();

	return 0;
}

