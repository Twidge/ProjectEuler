// Project Euler Problem 15.cpp
//
// Find the number of distinct lattice paths from top left to bottom right of a 20x20 grid moving only right one node or down one node

#include "stdafx.h"
#include <iostream>
#include <C:/Users/Matthew/Documents/GitHub/ProjectEuler/CommonFunctions.h>

const double G_GRID_SIZE = 20;

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "The number of lattice paths through a square grid of size " << G_GRID_SIZE << " is: "
		<< Combinations(2 * (G_GRID_SIZE), G_GRID_SIZE);
	std::cin.get();

	return 0;
}

/*
	I could solve this problem with recursion, but I decided to explicitly derive the formula instead, which for an n-by-n grid is:
	
	#LatticePaths = (2n)C(n)

	This originates from the observation that "staying inside the grid" amounts to having n down movements and n right movements in
	your path (which is of length 2n) so the number of lattice paths is the number of ways of placing n copies of "down" into 2n slots
	and filling the other slots with "right".
*/