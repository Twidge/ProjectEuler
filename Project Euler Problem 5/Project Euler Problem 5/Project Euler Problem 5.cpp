// Project Euler Problem 5.cpp
//
// What is the smallest positive number divisible by all the numbers from 1 to 20?

#include "stdafx.h"
#include <iostream>
#include <limits>

const unsigned int G_MAX_DIVISOR = 20;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int t_result = 0;

	// For each integer...
	for (unsigned int l_nextNumber = G_MAX_DIVISOR + 1; l_nextNumber < UINT_MAX; l_nextNumber++)
	{
		bool t_isCorrect = true;

		// Check if each number from 1 to the desired maximum divisor divides it

		for (unsigned int l_nextDivisor = 2; l_nextDivisor <= G_MAX_DIVISOR; l_nextDivisor++)
		{
			if (l_nextNumber % l_nextDivisor != 0)
			{
				t_isCorrect = false;
				break;
			}
		}

		// If it works, break

		if (t_isCorrect)
		{
			t_result = l_nextNumber;
			break;
		}
	}

	std::cout << "Largest number divisible by every number from 1 to " << G_MAX_DIVISOR << " is: " << t_result;
	std::cin.get();

	return 0;
}

