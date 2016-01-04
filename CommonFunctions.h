#include <cstdint>
#include <cmath>
#include <vector>

// Finds all prime factors, with multiplicities, of a number
std::vector<uint64_t> FindAllPrimeFactorsWithMultiplicities(uint64_t);

// Checks if a number is prime
bool IsPrime(uint64_t);

// Checks if three numbers form a Pythagorean triplet
bool IsPythagoreanTriple(uint64_t, uint64_t, uint64_t);

// uint64_t power function
uint64_t U64Power(uint64_t, int);

// Finds all prime factors, with multiplicities, of a number
std::vector<uint64_t> FindAllPrimeFactorsWithMultiplicities(uint64_t number)
{
	std::vector<uint64_t> t_primeFactors = std::vector<uint64_t>();

	uint64_t t_largestPossiblePrimeDivisor = static_cast<uint64_t>(sqrt(static_cast<double>(number)));

	// If the number is prime to start with, that's the only prime factor

	if (IsPrime(number))
	{
		t_primeFactors.push_back(number);
	}

	// Otherwise for each prime divisor, we add that divisor as many times as it divides the number

	else
	{
		for (uint64_t l_divisorToCheck = 2; l_divisorToCheck < t_largestPossiblePrimeDivisor; l_divisorToCheck++)
		{
			if (number % l_divisorToCheck == 0 && IsPrime(l_divisorToCheck))
			{
				t_primeFactors.push_back(l_divisorToCheck);

				uint64_t t_updatedNumber = number / l_divisorToCheck;

				while (t_updatedNumber % l_divisorToCheck == 0)
				{
					t_primeFactors.push_back(l_divisorToCheck);
					t_updatedNumber /= l_divisorToCheck;
				}
			}
		}
	}

	return t_primeFactors;
}

// Checks if a number is prime
bool IsPrime(uint64_t number)
{
	bool t_isPrime = true;
	uint64_t t_largestPossiblePrimeDivisor = static_cast<uint64_t>(sqrt(static_cast<double>(number)));

	if (number == 0 || number == 1)
	{
		t_isPrime = false;
	}

	else
	{
		for (uint64_t l_divisorToCheck = 2; l_divisorToCheck <= t_largestPossiblePrimeDivisor; l_divisorToCheck++)
		{
			if (number % l_divisorToCheck == 0)
			{
				t_isPrime = false;
				break;
			}
		}
	}

	return t_isPrime;
}

// Checks if three numbers form a Pythagorean triplet
bool IsPythagoreanTriple(uint64_t firstNumber, uint64_t secondNumber, uint64_t thirdNumber)
{
	bool t_isTriplet = false;

	// For each number, check if it's the sum of the squares of the other numbers

	if (U64Power(firstNumber, 2) == U64Power(secondNumber, 2) + U64Power(thirdNumber, 2)
		|| U64Power(secondNumber, 2) == U64Power(firstNumber, 2) + U64Power(thirdNumber, 2)
		|| U64Power(thirdNumber, 2) == U64Power(firstNumber, 2) + U64Power(secondNumber, 2))
	{
		t_isTriplet = true;
	}

	return t_isTriplet;
}

// uint64_t power function
uint64_t U64Power(uint64_t number, int exponent)
{
	return static_cast<uint64_t>(pow(static_cast<double>(number), exponent));
}