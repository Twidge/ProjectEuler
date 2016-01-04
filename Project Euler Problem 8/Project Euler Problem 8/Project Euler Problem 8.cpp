// Project Euler Problem 8
//
// Find the thirteen adjacent digits in a 1000-digit number that have the largest product

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdint>

const uint64_t G_NUMBER_OF_DIGITS = 1000;
const uint64_t G_CONSECUTIVE_NUMBERS = 13;
const std::string G_NUMBER_AS_STRING = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

int _tmain(int argc, _TCHAR* argv[])
{
	uint64_t t_maxProduct = 0;
	unsigned int t_numberToCheck[G_NUMBER_OF_DIGITS];

	// Load the numbers from the string into the array

	for (unsigned int l_nextLetter = 0; l_nextLetter < G_NUMBER_OF_DIGITS; l_nextLetter++)
	{
		// isdigit returns 0 if the character argument is not a digit

		if (l_nextLetter >= G_NUMBER_AS_STRING.length() || isdigit(G_NUMBER_AS_STRING[l_nextLetter]) == 0)
		{
			std::cout << "Error: letter in string is not a digit!\n";
			break;
		}

		else
		{
			// Convert the character in the string to a digit and put that in the array

			t_numberToCheck[l_nextLetter] = static_cast<int>(G_NUMBER_AS_STRING[l_nextLetter] - '0');
		}
	}

	// Check each product and return the maximum

	for (uint64_t l_nextIndex = 0; l_nextIndex < G_NUMBER_OF_DIGITS - G_CONSECUTIVE_NUMBERS; l_nextIndex++)
	{
		uint64_t t_product = 1;

		for (uint64_t l_nextDigit = 0; l_nextDigit < G_CONSECUTIVE_NUMBERS; l_nextDigit++)
		{
			t_product *= t_numberToCheck[l_nextIndex + l_nextDigit];
		}

		if (t_product > t_maxProduct)
		{
			t_maxProduct = t_product;
		}
	}

	std::cout << "The largest product of " << G_CONSECUTIVE_NUMBERS << " consecutive digits in the number specified is: " << t_maxProduct;
	std::cin.get();

	return 0;
}

