// Project Euler Problem 14
//
// Find the number under one million which produces the longest Collatz chain

#include "stdafx.h"
#include <iostream>
#include <C:/Users/Matthew/Documents/GitHub/ProjectEuler/CommonFunctions.h>

const unsigned int G_UPPER_BOUND = 1000000;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int t_maxChainLength = 0;
	unsigned int t_maxChainNumber = 0;

	// For each number, run Collatz() on it until we reach 1 then record the chain length

	for (unsigned int l_nextNumber = 1; l_nextNumber < G_UPPER_BOUND; l_nextNumber++)
	{
		unsigned int t_chainLength = 0;
		unsigned int t_nextStep = l_nextNumber;

		do
		{
			t_nextStep = Collatz(t_nextStep);
			t_chainLength++;
		} while (t_nextStep != 1);

		if (t_chainLength > t_maxChainLength)
		{
			t_maxChainLength = t_chainLength;
			t_maxChainNumber = l_nextNumber;
		}
	}

	std::cout << "Longest Collatz chain for a number under " << G_UPPER_BOUND << " is produced by: " << t_maxChainNumber;
	std::cin.get();
}

