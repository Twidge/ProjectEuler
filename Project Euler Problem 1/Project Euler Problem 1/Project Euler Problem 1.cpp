// Project Euler Problem 1
//
// Find the sum of all multiples of 3 or 5 below 1000.

#include "stdafx.h"
#include <iostream>

const unsigned int G_UPPER_BOUND = 1000;
const unsigned int G_NUMBER_OF_DIVISORS = 2;
const unsigned int G_DIVISORS[G_NUMBER_OF_DIVISORS] {3, 5};

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int t_result = 0;

	for (unsigned int l_nextNumber = 0; l_nextNumber < G_UPPER_BOUND; l_nextNumber++)
	{
		bool t_shouldAdd = false;

		for (unsigned int l_nextDivisor = 0; l_nextDivisor < G_NUMBER_OF_DIVISORS; l_nextDivisor++)
		{
			if (G_DIVISORS[l_nextDivisor] == 0)
			{
				std::cout << "Error! NextDivisor is 0.\n";
				break;
			}

			else if (l_nextNumber % G_DIVISORS[l_nextDivisor] == 0)
			{
				t_shouldAdd = true;
			}
		}

		if (t_shouldAdd)
		{
			t_result += l_nextNumber;
		}
	}

	std::cout << "The sum of all numbers less than " << G_UPPER_BOUND << " which divide the following numbers: ";

	for (unsigned int l_nextDivisor = 0; l_nextDivisor < G_NUMBER_OF_DIVISORS; l_nextDivisor++)
	{
		std::cout << G_DIVISORS[l_nextDivisor] << " ";
	}

	std::cout << "\n" << "is: " << t_result;

	std::cin.get();
}

