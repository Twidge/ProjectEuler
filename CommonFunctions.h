#include <cstdint>
#include <cmath>
#include <vector>

std::vector<uint64_t> FindAllPrimeFactorsWithMultiplicities(uint64_t);
bool IsPrime(uint64_t);

std::vector<uint64_t> FindAllPrimeFactorsWithMultiplicities(uint64_t number)
{
	std::vector<uint64_t> t_primeFactors = std::vector<uint64_t>();

	uint64_t largestPossibleDivisor = static_cast<uint64_t>(sqrt(static_cast<double>(number)));

	if (IsPrime(number))
	{
		t_primeFactors.push_back(number);
	}

	else
	{
		for (uint64_t divisorToCheck = 2; divisorToCheck < largestPossibleDivisor; divisorToCheck++)
		{
			if (number % divisorToCheck == 0 && IsPrime(divisorToCheck))
			{
				t_primeFactors.push_back(divisorToCheck);

				uint64_t t_updatedNumber = number / divisorToCheck;

				while (t_updatedNumber % divisorToCheck == 0)
				{
					t_primeFactors.push_back(divisorToCheck);
					t_updatedNumber /= divisorToCheck;
				}
			}
		}
	}

	return t_primeFactors;
}

bool IsPrime(uint64_t number)
{
	bool t_isPrime = true;
	uint64_t largestPossibleDivisor = static_cast<uint64_t>(sqrt(static_cast<double>(number)));

	if (number == 0 || number == 1)
	{
		t_isPrime = false;
	}

	else
	{
		for (uint64_t divisorToCheck = 2; divisorToCheck <= largestPossibleDivisor; divisorToCheck++)
		{
			if (number % divisorToCheck == 0)
			{
				t_isPrime = false;
				break;
			}
		}
	}

	return t_isPrime;
}