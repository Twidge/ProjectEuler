// Project Euler Problem 12
//
// Find the first triangle number to have more than five hundred divisors
// Note: tried this with Ramanujan divisor functions but they converge incredibly slowly so not computationally feasible

#include "stdafx.h"
#include <iostream>
#include <C:/Users/Matthew/Documents/GitHub/ProjectEuler/CommonFunctions.h>

const unsigned int G_DIVISOR_LOWER_BOUND = 500;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int t_result = 0;

	for (unsigned int l_nextNumber = 2; l_nextNumber < INT_MAX; l_nextNumber++)
	{
		unsigned int t_divisors = FindAmountOfDivisors(TriangleNumber(l_nextNumber));

		if (t_divisors > G_DIVISOR_LOWER_BOUND)
		{
			t_result = l_nextNumber;
			break;
		}
	}

	std::cout << "The first triangle number to have more than " << G_DIVISOR_LOWER_BOUND << " divisors is: " << TriangleNumber(t_result);
	std::cin.get();

	return 0;
}