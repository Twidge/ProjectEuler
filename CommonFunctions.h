#include <cstdint>
#include <cmath>
#include <vector>
#include <list>

/*
	*********
	CONSTANTS
	*********
*/

const double G_RAMANUJAN_CONVERGENCE_BOUND = 0.01;
const double G_PI = 3.14159265358979323846;

/*
	*********
	PROTOTYPES
	*********
*/

// Checks if two numbers are coprime
bool AreCoprime(unsigned int, unsigned int);

// Takes a number and produces the next number in the Collatz sequence
inline unsigned int Collatz(unsigned int n) { return (n % 2 == 0 ? (n / 2) : (3 * n) + 1); }

// Combinations: returns the number of ways of choosing k elements from a set of n elements without repeats
uint64_t Combinations(double parentSetSize, double subsetSize);

// Finds all divisors of a number
std::list<unsigned int> FindAllDivisorsAsList(unsigned int);
std::list<uint64_t> FindAllDivisorsAsList(uint64_t);
std::vector<unsigned int> FindAllDivisorsAsVector(unsigned int);
std::vector<uint64_t> FindAllDivisorsAsVector(uint64_t);

// Finds all prime factors of a number
std::vector<unsigned int> FindAllPrimeFactors(unsigned int);

// Finds all prime factors, with multiplicities, of a number
std::vector<uint64_t> FindAllPrimeFactorsWithMultiplicities(uint64_t);

// Finds the amount of divisors of a number
unsigned int FindAmountOfDivisors(unsigned int);

// Checks if a number is prime
bool IsPrime(unsigned int);
bool IsPrime(uint64_t);

// Checks if three numbers form a Pythagorean triplet
bool IsPythagoreanTriple(uint64_t, uint64_t, uint64_t);

// Ramanujan divisor function - finds the number of divisors of an integer
unsigned int RamanujanDivisorFunction(int);

// Generates the nth triangle number
unsigned int TriangleNumber(unsigned int);
uint64_t TriangleNumber(uint64_t);

// uint64_t power function
uint64_t U64Power(uint64_t, int);

/*
	*********
	FUNCTIONS
	*********
*/

// Checks if two numbers are coprime
bool AreCoprime(unsigned int firstNumber, unsigned int secondNumber)
{
	std::vector<unsigned int> t_firstNumberPrimes = FindAllPrimeFactors(firstNumber);
	std::vector<unsigned int> t_secondNumberPrimes = FindAllPrimeFactors(secondNumber);

	bool t_areCoprime = true;

	for (unsigned int l_firstNumberIndex = 0; l_firstNumberIndex < t_firstNumberPrimes.size(); l_firstNumberIndex++)
	{
		for (unsigned int l_secondNumberIndex = 0; l_secondNumberIndex < t_secondNumberPrimes.size(); l_secondNumberIndex++)
		{
			if (t_firstNumberPrimes[l_firstNumberIndex] == t_secondNumberPrimes[l_secondNumberIndex])
			{
				t_areCoprime = false;
				break;
			}
		}

		if (!t_areCoprime)
		{
			break;
		}
	}

	return t_areCoprime;
}

// Combinations: returns the number of ways of choosing k elements from a set of n elements without repeats
uint64_t Combinations(double parentSetSize, double subsetSize)
{
	double t_result = 1;

	// Rather than calculating the factorials directly, which is infeasible, this uses the multiplicative formula

	for (double l_nextNumber = 1; l_nextNumber <= subsetSize; l_nextNumber++)
	{
		t_result *= ((parentSetSize + 1 - l_nextNumber) / l_nextNumber);
	}

	return static_cast<uint64_t>(t_result);
}

// Finds all divisors of a number, returns a list
// Better if we only need to check amount of divisors
std::list<unsigned int> FindAllDivisorsAsList(unsigned int number)
{
	std::list<unsigned int> t_divisors = std::list<unsigned int>();

	for (unsigned int l_nextNumber = 1; l_nextNumber <= number / 2; l_nextNumber++)
	{
		if (number % l_nextNumber == 0)
		{
			t_divisors.push_back(l_nextNumber);
		}
	}

	return t_divisors;
}

std::list<uint64_t> FindAllDivisorsAsList(uint64_t number)
{
	std::list<uint64_t> t_divisors = std::list<uint64_t>();

	for (uint64_t l_nextNumber = 1; l_nextNumber <= number / 2; l_nextNumber++)
	{
		if (number % l_nextNumber == 0)
		{
			t_divisors.push_back(l_nextNumber);
		}
	}

	return t_divisors;
}

// Finds all divisors of a number, returns a vector
// Better if we need to then do lots of accessing of divisors
std::vector<unsigned int> FindAllDivisorsAsVector(unsigned int number)
{
	std::vector<unsigned int> t_divisors = std::vector<unsigned int>();

	for (unsigned int l_nextNumber = 1; l_nextNumber <= number / 2; l_nextNumber++)
	{
		if (number % l_nextNumber == 0)
		{
			t_divisors.push_back(l_nextNumber);
		}
	}

	return t_divisors;
}

std::vector<uint64_t> FindAllDivisorsAsVector(uint64_t number)
{
	std::vector<uint64_t> t_divisors = std::vector<uint64_t>();

	for (uint64_t l_nextNumber = 1; l_nextNumber <= number / 2; l_nextNumber++)
	{
		if (number % l_nextNumber == 0)
		{
			t_divisors.push_back(l_nextNumber);
		}
	}

	return t_divisors;
}

// Finds all prime factors of a number
std::vector<unsigned int> FindAllPrimeFactors(unsigned int number)
{
	std::vector<unsigned int> t_primeFactors = std::vector<unsigned int>();

	unsigned int t_largestPossiblePrimeDivisor = static_cast<unsigned int>(sqrt(static_cast<double>(number)));

	// If the number is prime to start with, that's the only prime factor

	if (IsPrime(number))
	{
		t_primeFactors.push_back(number);
	}

	// Otherwise for each prime divisor, we add that divisor as many times as it divides the number

	else
	{
		for (unsigned int l_divisorToCheck = 2; l_divisorToCheck < t_largestPossiblePrimeDivisor; l_divisorToCheck++)
		{
			if (number % l_divisorToCheck == 0 && IsPrime(l_divisorToCheck))
			{
				t_primeFactors.push_back(l_divisorToCheck);
			}
		}
	}

	return t_primeFactors;
}

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

// Finds the amount of divisors of a number
unsigned int FindAmountOfDivisors(unsigned int number)
{
	unsigned int t_numberOfDivisors = 0;

	// We can do this iterating only up to the square root of the number

	for (unsigned int l_nextNumber = 1; l_nextNumber <= static_cast<unsigned int>(sqrt(static_cast<double>(number))); l_nextNumber++)
	{
		if (number % l_nextNumber == 0)
		{
			// Add the number we're checking and the argument divided by that number

			t_numberOfDivisors += 2;
		}
	}

	return t_numberOfDivisors;
}

// Checks if a number is prime
bool IsPrime(unsigned int number)
{
	bool t_isPrime = true;
	unsigned int t_largestPossiblePrimeDivisor = static_cast<unsigned int>(sqrt(static_cast<double>(number)));

	if (number == 0 || number == 1)
	{
		t_isPrime = false;
	}

	else
	{
		for (unsigned int l_divisorToCheck = 2; l_divisorToCheck <= t_largestPossiblePrimeDivisor; l_divisorToCheck++)
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

// Ramanujan divisor function - finds the number of divisors of an integer
unsigned int RamanujanDivisorFunction(int number)
{
	// Let d(n) be the number of divisors of n.
	// Then d(n) = -1 * ((log 1 / 1)c_1(n) + (log 2 / 2)c_2(n) + (log 3 / 3)c_3(n) + ...)
	// where c_1(n) = 1 and, for k > 1, c_k(n) = sum over a in [1, k] (such that a and k are coprime) of e^{2*pi*i*n*a/k}
	// We can rearrange c_k(n) using trig to get the sum of cos (2*pi*n*a/k) for a in [1, k] such that a and k are coprime

	double t_numberOfDivisors = 0;
	double t_numberOfDivisorsPreviousStep = 0;

	// Can skip k = 1 because log 1 = 0

	unsigned int t_valueOfK = 2;

	do
	{
		t_numberOfDivisorsPreviousStep = t_numberOfDivisors;

		double t_c_kOfN = 0;

		for (unsigned int l_nextNumber = 1; l_nextNumber <= t_valueOfK; l_nextNumber++)
		{
			if (l_nextNumber == 1 || AreCoprime(l_nextNumber, t_valueOfK))
			{
				t_c_kOfN += cos(static_cast<double>(2 * G_PI * number * l_nextNumber / t_valueOfK));
			}
		}

		t_numberOfDivisors += ((log(t_valueOfK) / t_valueOfK) * t_c_kOfN);
		t_valueOfK++;
	} while (abs(t_numberOfDivisors - t_numberOfDivisorsPreviousStep) > G_RAMANUJAN_CONVERGENCE_BOUND);

	t_numberOfDivisors *= -1;

	return static_cast<unsigned int>(t_numberOfDivisors);
}

// Generates the nth triangle number
unsigned int TriangleNumber(unsigned int n)
{
	return (n * (n + 1) / 2);
}

uint64_t TriangleNumber(uint64_t n)
{
	return (n * (n + 1) / 2);
}

// uint64_t power function
uint64_t U64Power(uint64_t number, int exponent)
{
	return static_cast<uint64_t>(pow(static_cast<double>(number), exponent));
}