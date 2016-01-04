// Project Euler Problem 4.cpp
//
// Find the largest palindromic number made from the product of two 3-digit numbers

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

bool IsPalindrome(int);

const int G_NUMBER_OF_DIGITS = 3;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int t_lowerLimit = static_cast<unsigned int>(pow(static_cast<double>(10), G_NUMBER_OF_DIGITS - 1));

	unsigned int t_maxPalindrome = 0;

	// Let n be the number of digits. For every uint in the range [10^(n-1), 10^n - 1] (starting at the top) multiply by every
	// uint in the same range and check if the result is a palindrome. Keep track of the maximum.

	for (unsigned int l_firstNextNumber = static_cast<unsigned int>(pow(static_cast<double>(10), G_NUMBER_OF_DIGITS)) - 1;
		l_firstNextNumber > t_lowerLimit; l_firstNextNumber--)
	{
		for (unsigned int l_secondNextNumber = static_cast<unsigned int>(pow(static_cast<double>(10), G_NUMBER_OF_DIGITS)) - 1;
			l_secondNextNumber > t_lowerLimit; l_secondNextNumber--)
		{
			unsigned int t_candidate = l_firstNextNumber * l_secondNextNumber;

			if (IsPalindrome(t_candidate) && t_candidate > t_maxPalindrome)
			{
				t_maxPalindrome = t_candidate;
			}

			// Slight optimisation - breaks if it goes below t_maxPalindrome (since the second number is going down, so the product
			// goes down)

			else if (t_candidate <= t_maxPalindrome)
			{
				break;
			}
		}
	}

	std::cout << "Largest palindrome which is a product of two " << G_NUMBER_OF_DIGITS << " digit numbers is: " << t_maxPalindrome;
	std::cin.get();
}

bool IsPalindrome(int number)
{
	std::string t_stringRepresentation = std::to_string(number);

	bool t_isPalindrome = true;

	for (unsigned int l_nextLetter = 0; l_nextLetter < t_stringRepresentation.length() / 2; l_nextLetter++)
	{
		if (t_stringRepresentation[l_nextLetter] != t_stringRepresentation[t_stringRepresentation.length() - 1 - l_nextLetter])
		{
			t_isPalindrome = false;
		}
	}

	return t_isPalindrome;
}

