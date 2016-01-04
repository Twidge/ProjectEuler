// Project Euler Problem 3.cpp
//
// Find the largest prime that divides 600851475143

#include "stdafx.h"
#include <iostream>
#include <C:/Users/Matthew/Documents/GitHub/ProjectEuler/CommonFunctions.h>

const uint64_t G_NUMBER_TO_CHECK = 600851475143;

bool IsPrime(uint64_t);

int _tmain(int argc, _TCHAR* argv[])
{
	uint64_t t_result = 0;

	for (uint64_t numberToCheck = static_cast<uint64_t>(sqrt(static_cast<double>(G_NUMBER_TO_CHECK)));
		numberToCheck > 2; numberToCheck--)
	{
		if (G_NUMBER_TO_CHECK % numberToCheck == 0)
		{
			if (IsPrime(numberToCheck))
			{
				t_result = numberToCheck;
				break;
			}
		}
	}

	std::cout << "Largest prime that divides " << G_NUMBER_TO_CHECK << " is: " << t_result;
	std::cin.get();

	return 0;
}