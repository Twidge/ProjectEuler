// Project Euler Problem 17
//
// How many letters are used when writing out the numbers from 1 (one) to 1000 (one thousand) by hand?

#include "stdafx.h"
#include <iostream>
#include <string>

const int G_MAX_CONVERSION_SIZE = 1000;

std::string ConvertSecondDigit(unsigned int, unsigned int);
std::string ConvertToString(unsigned int);

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int t_result = 0;

	for (unsigned int l_nextNumber = 1; l_nextNumber <= G_MAX_CONVERSION_SIZE; l_nextNumber++)
	{
		std::string t_asString = ConvertToString(l_nextNumber);
		std::cout << t_asString << "\n";
		t_result += t_asString.length();
	}

	std::cout << "The amount of letters used when writing out the numbers from 1 to " << G_MAX_CONVERSION_SIZE << "by hand is: " << t_result;
	std::cin.get();
}

// A function that converts the second digit into eleven, twelve, ..., nineteen and twenty, thirty, forty, fifty, ...

std::string ConvertSecondDigit(unsigned int secondDigit, unsigned int firstDigit)
{
	std::string t_result = "";

	if (secondDigit == 1)
	{
		switch (firstDigit)
		{
		case 0 :
			t_result += "ten";
			break;

		case 1 :
			t_result += "eleven";
			break;

		case 2 :
			t_result += "twelve";
			break;

		case 3 :
			t_result += "thirteen";
			break;

		case 4 :
			t_result += "fourteen";
			break;

		case 5 :
			t_result += "fifteen";
			break;

		case 6 :
			t_result += "sixteen";
			break;

		case 7 :
			t_result += "seventeen";
			break;

		case 8 :
			t_result += "eighteen";
			break;

		case 9 :
			t_result += "nineteen";
			break;

		default :
			std::cout << "Error in ConvertSecondDigit(): first digit was something weird.\n";
			std::cin.get();
		}
	}

	else
	{
		switch (secondDigit)
		{
		case 2 :
			t_result += "twenty";
			break;

		case 3 :
			t_result += "thirty";
			break;

		case 4 :
			t_result += "forty";
			break;

		case 5 :
			t_result += "fifty";
			break;

		case 6 :
			t_result += "sixty";
			break;

		case 7 :
			t_result += "seventy";
			break;

		case 8 :
			t_result += "eighty";
			break;

		case 9 :
			t_result += "ninety";
			break;

		default :
			std::cout << "Error in ConvertSecondDigit(): second digit was something weird.\n";
			std::cin.get();
		}

		if (firstDigit != 0)
		{
			t_result += ConvertToString(firstDigit);
		}
	}

	return t_result;
}

// Converts a positive integer in the range [1, G_MAX_CONVERSION_SIZE] to its string representation (in English)
// WARNING: Undefined behaviour above 1000

std::string ConvertToString(unsigned int number)
{
	// NOTE: we're ignoring spaces and hyphens here; we don't actually mind if the string is readable, only how many letters are used in it

	std::string t_result = "";
	unsigned int t_numberOfDigits = static_cast<unsigned int>(log10(number)) + 1;
	unsigned int* t_digits = new unsigned int[t_numberOfDigits];

	if (number > G_MAX_CONVERSION_SIZE || number == 0)
	{
		std::cout << "Error in ConvertToString(): number is zero or above 1000.\n";
		std::cin.get();
	}

	else
	{
		// Populate array of digits

		for (unsigned int l_index = 0; l_index < t_numberOfDigits; l_index++)
		{
			*(t_digits + l_index) = (number % static_cast<unsigned int>(pow(10, t_numberOfDigits - l_index)))
				/ static_cast<unsigned int>(pow(10, t_numberOfDigits - l_index - 1));
		}

		// If number is 1000, set the string to "onethousand"

		if (number == 1000)
		{
			t_result += "onethousand";
		}

		else
		{
			// Otherwise, if the number has three digits, set the string to be X hundred and whatever the last two digits are

			if (t_numberOfDigits == 3)
			{
				t_result += ConvertToString(t_digits[0]) + "hundred";
				
				if (t_digits[1] != 0)
				{
					t_result += "and" + ConvertSecondDigit(t_digits[1], t_digits[2]);
				}

				else if (t_digits[2] != 0)
				{
					t_result += "and" + ConvertToString(t_digits[2]);
				}
			}

			// If the number has two digits, just work it out directly

			else if (t_numberOfDigits == 2)
			{
				t_result += ConvertSecondDigit(t_digits[0], t_digits[1]);
			}

			// If the number has one digit (base case) just work it out directly as well

			else if (t_numberOfDigits == 1)
			{
				switch (t_digits[0])
				{
				case 1 :
					t_result += "one";
					break;

				case 2 :
					t_result += "two";
					break;

				case 3 :
					t_result += "three";
					break;
					
				case 4 :
					t_result += "four";
					break;

				case 5 :
					t_result += "five";
					break;

				case 6 :
					t_result += "six";
					break;

				case 7 :
					t_result += "seven";
					break;

				case 8 :
					t_result += "eight";
					break;

				case 9 :
					t_result += "nine";
					break;

				default :
					std::cout << "Error in ConvertToString(): number is one digit but something weird.\n";
					std::cin.get();
				}
			}
		}
	}

	delete[] t_digits;

	return t_result;
}