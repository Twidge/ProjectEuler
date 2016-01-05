// Project Euler Problem 13
//
// Find the first ten digits of the sum of 100 fifty-digit numbers

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdint>

const unsigned int G_AMOUNT_OF_NUMBERS = 100;
const unsigned int G_DESIRED_DIGITS = 10;

int _tmain(int argc, _TCHAR* argv[])
{
	// The amount of digits on the front of the numbers that contribute to the desired digits is the number of desired digits plus the
	// base 10 log of the amount of numbers (not exactly, but near enough - this is a slight overestimate)

	unsigned int t_relevantDigits = G_DESIRED_DIGITS + static_cast<unsigned int>(log10(static_cast<double>(G_AMOUNT_OF_NUMBERS)));

	std::ifstream t_fileReader;
	uint64_t* t_firstDigits = new uint64_t[G_AMOUNT_OF_NUMBERS];

	t_fileReader.open("numbers.txt");

	if (t_fileReader.is_open())
	{
		// Read strings and extract group of relevant digits from the front

		for (unsigned int l_nextNumber = 0; l_nextNumber < G_AMOUNT_OF_NUMBERS; l_nextNumber++)
		{
			std::string t_numberAsString = "";
			uint64_t t_number = 0;

			t_fileReader >> t_numberAsString;

			for (unsigned int l_nextDigit = 0; l_nextDigit < t_relevantDigits; l_nextDigit++)
			{
				t_number += static_cast<uint64_t>((t_numberAsString[l_nextDigit] - '0')
					* (pow(10, t_relevantDigits - 1 - l_nextDigit)));
			}

			*(t_firstDigits + l_nextNumber) = t_number;
		}

		t_fileReader.close();

		// Sum the numbers in the array

		uint64_t t_finalNumber = 0;

		for (unsigned int l_index = 0; l_index < G_AMOUNT_OF_NUMBERS; l_index++)
		{
			t_finalNumber += *(t_firstDigits + l_index);
		}

		// Chop off the last digits - note the extra digits from adding so many numbers with t_relevantDigits digits means we should lop off
		// log10(amount of numbers) extra digits

		t_finalNumber /= static_cast<uint64_t>(pow(10, t_relevantDigits - G_DESIRED_DIGITS
			+ static_cast<unsigned int>(log10(static_cast<double>(G_AMOUNT_OF_NUMBERS)))));

		std::cout << "First " << G_DESIRED_DIGITS << " digits of the sum of the numbers is: " << t_finalNumber;
		std::cin.get();
	}

	else
	{
		std::cout << "Error: could not open numbers.txt.\n";
		std::cin.get();
	}

	return 0;
}

