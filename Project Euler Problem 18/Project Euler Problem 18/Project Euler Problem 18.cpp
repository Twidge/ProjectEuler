// Project Euler Problem 18
//
// Find the largest weight path from top to bottom, moving left or right at each stage, in a Pascal's-Triangle-style grid of integers

#include "stdafx.h"
#include <iostream>
#include <C:/Users/Matthew/Documents/GitHub/ProjectEuler/CommonFunctions.h>
#include <C:/Users/Matthew/Documents/GitHub/ProjectEuler/EulerTemplateGridClasses.h>

const unsigned int G_NUMBER_OF_ROWS = 15;

int _tmain(int argc, _TCHAR* argv[])
{
	TriangularGrid<unsigned int> t_grid = TriangularGrid<unsigned int>();

	t_grid.ParseGrid("grid.txt", G_NUMBER_OF_ROWS);

	unsigned int t_longestPath = t_grid.FindLongestPath();

	std::cout << "Longest path has length: " << t_longestPath << ".\n";

	std::cin.get();

	return 0;
}

