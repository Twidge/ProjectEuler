// Project Euler Problem 16
//
// Find the sum of the digits of 2^1000

#include "stdafx.h"
#include <iostream>
#include <C:/Users/Matthew/Documents/GitHub/ProjectEuler/CommonFunctions.h>

const unsigned int G_POWER_OF_TWO_TO_CHECK = 10000;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int t_result = 0;
	std::vector<short> t_largePower = LargePowerOfTwo(G_POWER_OF_TWO_TO_CHECK);

	for (unsigned int l_index = 0; l_index < t_largePower.size(); l_index++)
	{
		t_result += t_largePower[l_index];
	}

	std::cout << "The sum of the digits of 2^" << G_POWER_OF_TWO_TO_CHECK << " is: " << t_result;
	std::cin.get();
}

