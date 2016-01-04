// Project Euler Problem 9
//
// There is a unique Pythagorean triplet (a, b, c) such that a + b + c = 1000. Let (a, b, c) be this triplet. Find abc.

#include "stdafx.h"
#include <iostream>
#include <C:/Users/Matthew/Documents/GitHub/ProjectEuler/CommonFunctions.h>

uint64_t G_TARGET_SUM = 1000;

int _tmain(int argc, _TCHAR* argv[])
{
	uint64_t t_product = 1;
	uint64_t t_triple[3];
	bool t_tripleFound = false;

	// Check every combination of three numbers that sum to the desired sum to see if they form a Pythagorean triple

	for (uint64_t l_firstNumber = G_TARGET_SUM - 2; l_firstNumber >= 1; l_firstNumber--)
	{
		for (uint64_t l_secondNumber = G_TARGET_SUM - 1 - l_firstNumber; l_secondNumber >= 1; l_secondNumber--)
		{
			if (IsPythagoreanTriple(l_firstNumber, l_secondNumber, G_TARGET_SUM - l_firstNumber - l_secondNumber))
			{
				t_triple[0] = l_firstNumber;
				t_triple[1] = l_secondNumber;
				t_triple[2] = G_TARGET_SUM - l_firstNumber - l_secondNumber;

				t_tripleFound = true;
				break;
			}
		}

		if (t_tripleFound)
		{
			break;
		}
	}

	for (unsigned int l_index = 0; l_index < 3; l_index++)
	{
		t_product *= t_triple[l_index];
	}

	std::cout << "The first triple found summing to " << G_TARGET_SUM << " is: ";

	for (unsigned int l_index = 0; l_index < 3; l_index++)
	{
		std::cout << t_triple[l_index] << " ";
	}

	std::cout << "\n" << "Their product is: " << t_product;
	std::cin.get();

	return 0;
}

