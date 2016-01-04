// Project Euler Problem 11
//
// Find the greatest product of four adjacent numbers (up, down, left, right or diagonal) in a 20x20 grid
// Did this one without STL because it's good practice!

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "C:/Users/Matthew/Documents/GitHub/ProjectEuler/EulerTemplateFunctions.cpp"

enum Direction
{
	Left,
	Right,
	Up,
	Down,
	Diagonal
};

unsigned int LargestDirectionalProduct(unsigned int **, unsigned int, unsigned int, Direction);

const unsigned int G_GRID_SIZE = 20;
const unsigned int G_CONSECUTIVE_INTS = 4;

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream t_fileReader;
	unsigned int** t_grid = new unsigned int*[G_GRID_SIZE];
	unsigned int t_result = 0;

	for (unsigned int l_index = 0; l_index < G_GRID_SIZE; l_index++)
	{
		*(t_grid + l_index) = new unsigned int[G_GRID_SIZE];
	}

	t_fileReader.open("grid.txt");

	// Read grid.txt, transfer to grid array

	for (unsigned int l_firstGridIndex = 0; l_firstGridIndex < G_GRID_SIZE; l_firstGridIndex++)
	{
		for (unsigned int l_secondGridIndex = 0; l_secondGridIndex < G_GRID_SIZE; l_secondGridIndex++)
		{
			unsigned int t_nextNumber = 0;

			t_fileReader >> t_nextNumber;

			*(*(t_grid + l_firstGridIndex) + l_secondGridIndex) = t_nextNumber;
		}
	}

	t_fileReader.close();

	// Return largest product of consecutive integers in each direction, take maximum
	// Note checking left/right is the same by symmetry and checking up/down is the same by symmetry

	t_result = Max(LargestDirectionalProduct(t_grid, G_GRID_SIZE, G_GRID_SIZE, Left),
		Max(LargestDirectionalProduct(t_grid, G_GRID_SIZE, G_GRID_SIZE, Up),
		LargestDirectionalProduct(t_grid, G_GRID_SIZE, G_GRID_SIZE, Diagonal)));

	for (unsigned int l_index = 0; l_index < G_GRID_SIZE; l_index++)
	{
		delete[] *(t_grid + l_index);
	}

	delete[] t_grid;

	std::cout << "Largest product of any " << G_CONSECUTIVE_INTS << " adjacent numbers in the grid is: " << t_result;
	std::cin.get();

	return 0;
}

// Returns the largest product of the desired amount of adjacent numbers from the grid in a given direction (left, right, up, down, diagonal)

unsigned int LargestDirectionalProduct(unsigned int ** grid, unsigned int xSize, unsigned int ySize, Direction direction)
{
	unsigned int t_maxProduct = 0;

	// Only actually need to consider one of left/right, one of up/down because the problem is symmetrical

	if (direction == Left || direction == Right)
	{
		for (unsigned int l_firstGridIndex = 0; l_firstGridIndex < xSize - G_CONSECUTIVE_INTS; l_firstGridIndex++)
		{
			for (unsigned int l_secondGridIndex = 0; l_secondGridIndex < ySize; l_secondGridIndex++)
			{
				unsigned int t_product = 1;

				for (unsigned int l_consecutiveInts = 0; l_consecutiveInts < G_CONSECUTIVE_INTS; l_consecutiveInts++)
				{
					t_product *= *(*(grid + l_firstGridIndex + l_consecutiveInts) + l_secondGridIndex);
				}

				if (t_product > t_maxProduct)
				{
					t_maxProduct = t_product;
				}
			}
		}
	}

	else if (direction == Up || direction == Down)
	{
		for (unsigned int l_firstGridIndex = 0; l_firstGridIndex < xSize; l_firstGridIndex++)
		{
			for (unsigned int l_secondGridIndex = 0; l_secondGridIndex < ySize - G_CONSECUTIVE_INTS; l_secondGridIndex++)
			{
				unsigned int t_product = 1;

				for (unsigned int l_consecutiveInts = 0; l_consecutiveInts < G_CONSECUTIVE_INTS; l_consecutiveInts++)
				{
					t_product *= *(*(grid + l_firstGridIndex) + l_secondGridIndex + l_consecutiveInts);
				}

				if (t_product > t_maxProduct)
				{
					t_maxProduct = t_product;
				}
			}
		}
	}

	// Do the diagonals next

	else if (direction == Diagonal)
	{
		// Do top-left-to-bottom-right diagonals first, then top-right-to-bottom-left

		for (unsigned int l_firstGridIndex = 0; l_firstGridIndex < xSize - G_CONSECUTIVE_INTS; l_firstGridIndex++)
		{
			for (unsigned int l_secondGridIndex = 0; l_secondGridIndex < ySize - G_CONSECUTIVE_INTS; l_secondGridIndex++)
			{
				unsigned int t_product = 1;

				for (unsigned int l_consecutiveInts = 0; l_consecutiveInts < G_CONSECUTIVE_INTS; l_consecutiveInts++)
				{
					t_product *= *(*(grid + l_firstGridIndex + l_consecutiveInts) + l_secondGridIndex + l_consecutiveInts);
				}

				if (t_product > t_maxProduct)
				{
					t_maxProduct = t_product;
				}
			}
		}

		for (unsigned int l_firstGridIndex = xSize - 1; l_firstGridIndex >= G_CONSECUTIVE_INTS; l_firstGridIndex--)
		{
			for (unsigned int l_secondGridIndex = 0; l_secondGridIndex < ySize - G_CONSECUTIVE_INTS; l_secondGridIndex++)
			{
				unsigned int t_product = 1;

				for (unsigned int l_consecutiveInts = 0; l_consecutiveInts < G_CONSECUTIVE_INTS; l_consecutiveInts++)
				{
					t_product *= *(*(grid + l_firstGridIndex - l_consecutiveInts) + l_secondGridIndex + l_consecutiveInts);
				}

				if (t_product > t_maxProduct)
				{
					t_maxProduct = t_product;
				}
			}
		}
	}

	return t_maxProduct;
}