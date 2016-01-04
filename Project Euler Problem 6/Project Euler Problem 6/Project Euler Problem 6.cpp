// Project Euler Problem 6
//
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum

#include "stdafx.h"
#include <iostream>
#include <cstdint>
#include <cmath>

const uint64_t G_UPPER_BOUND = 100;

int _tmain(int argc, _TCHAR* argv[])
{
	uint64_t t_sumOfSquares = 0;
	uint64_t t_sum = 0;
	uint64_t t_result = 0;

	for (uint64_t nextNumber = 1; nextNumber <= G_UPPER_BOUND; nextNumber++)
	{
		t_sum += nextNumber;
		t_sumOfSquares += static_cast<uint64_t>(pow(static_cast<double>(nextNumber), 2));
	}

	t_result = static_cast<uint64_t>(pow(static_cast<double>(t_sum), 2)) - t_sumOfSquares;

	std::cout << "The difference between the square of the sum of the first " << G_UPPER_BOUND << " numbers and the sum of the first "
		<< G_UPPER_BOUND << " squares is: " << t_result;

	std::cin.get();

	return 0;
}

