// Project Euler Problem 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdint>
#include <limits>
#include <cmath>

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

bool IsPrime(uint64_t number)
{
	bool t_isPrime = true;
	uint64_t largestPossibleDivisor = static_cast<uint64_t>(sqrt(static_cast<double>(number)));

	for (uint64_t divisorToCheck = 2; divisorToCheck < largestPossibleDivisor; divisorToCheck++)
	{
		if (number % divisorToCheck == 0)
		{
			t_isPrime = false;
			break;
		}
	}

	return t_isPrime;
}

