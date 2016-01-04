// Project Euler Problem 2.cpp
//
// Find the sum of the even Fibonacci numbers less than or equal to four million

#include "stdafx.h"
#include <iostream>

const unsigned int G_UPPER_BOUND = 4000000;
const unsigned int G_PREVIOUS_FIB_NUMBER_ARRAY_SIZE = 2;
const unsigned int G_NUMBER_OF_DIVISORS = 1;
const unsigned int G_DIVISORS[G_NUMBER_OF_DIVISORS] {2};

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int t_result = 0;

	// Keep track of the last x Fibonacci numbers, for a given x

	unsigned int t_lastFibonacciNumbers[G_PREVIOUS_FIB_NUMBER_ARRAY_SIZE] {1, 1};

	// Work out next Fibonacci number, update array (fastest when we only keep track of last 2 Fibonacci numbers) and add to the
	// total if it is divisible by every divisor listed

	while (t_lastFibonacciNumbers[G_PREVIOUS_FIB_NUMBER_ARRAY_SIZE - 1] <= G_UPPER_BOUND)
	{
		unsigned int t_newNumber =
			t_lastFibonacciNumbers[G_PREVIOUS_FIB_NUMBER_ARRAY_SIZE - 2] + t_lastFibonacciNumbers[G_PREVIOUS_FIB_NUMBER_ARRAY_SIZE - 1];

		for (unsigned int lastNumbersIndex = 0; lastNumbersIndex < G_PREVIOUS_FIB_NUMBER_ARRAY_SIZE - 1; lastNumbersIndex++)
		{
			t_lastFibonacciNumbers[lastNumbersIndex] = t_lastFibonacciNumbers[lastNumbersIndex + 1];
		}

		t_lastFibonacciNumbers[G_PREVIOUS_FIB_NUMBER_ARRAY_SIZE - 1] = t_newNumber;

		// Check if the new number is divisible by everything listed

		bool t_shouldAdd = true;

		for (unsigned int l_nextDivisor = 0; l_nextDivisor < G_NUMBER_OF_DIVISORS; l_nextDivisor++)
		{
			if (G_DIVISORS[l_nextDivisor] == 0)
			{
				std::cout << "Error! Next divisor is 0.\n";
				break;
			}

			if (t_newNumber % G_DIVISORS[l_nextDivisor] != 0)
			{
				t_shouldAdd = false;
			}
		}

		if (t_shouldAdd)
		{
			t_result += t_newNumber;
		}
	}

	std::cout << "The sum of the Fibonacci numbers less than or equal to " << G_UPPER_BOUND << " which are divisible by all the following numbers: ";

	for (unsigned int l_nextDivisor = 0; l_nextDivisor < G_NUMBER_OF_DIVISORS; l_nextDivisor++)
	{
		std::cout << G_DIVISORS[l_nextDivisor] << " ";
	}

	std::cout << "\n" << "is: " << t_result;

	std::cin.get();
}

