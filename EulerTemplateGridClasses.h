#include <vector>
#include <fstream>
#include <iostream>

template<typename T>
class Grid2D
{
public :

	// CONSTRUCTORS

	Grid2D();
	Grid2D(std::string const&, unsigned int);

	// METHODS

	void ParseGrid(std::string const&, unsigned int);

	// Disable copy constructor and assignment operator

	Grid2D(Grid2D const&);
	void operator= (Grid2D const&);

protected :

	std::vector<std::vector<T>> m_gridValues;
	unsigned int m_size;
};

template<typename T>
class TriangularGrid : public Grid2D<T>
{
public :

	// CONSTRUCTORS

	TriangularGrid();
	TriangularGrid(std::string const&, unsigned int);

	// METHODS

	unsigned int FindLongestPath();
	void ParseGrid(std::string const&, unsigned int);

	// OPERATOR OVERLOADS

	template<typename U>
	friend std::ostream& operator<< (std::ostream&, TriangularGrid<U> const&);

	// Disable copy constructor and assignment operator

	TriangularGrid(TriangularGrid const&);
	void operator= (TriangularGrid const&);

private :


};

/*
*********
GRID
*********
*/

// CONSTRUCTORS

template<typename T>
Grid2D<T>::Grid2D()
{
	m_gridValues = std::vector<std::vector<T>>();
}

template<typename T>
Grid2D<T>::Grid2D(std::string const& filename, unsigned int size)
{
	m_gridValues = std::vector<std::vector<T>>();
	m_size = size;

	ParseGrid(filename, size);
}

// METHODS

template<typename T>
void Grid2D<T>::ParseGrid(std::string const& filename, unsigned int size)
{
	std::ifstream t_fileReader;

	t_fileReader.open(filename);

	if (t_fileReader.is_open())
	{
		m_gridValues = std::vector<std::vector<T>>();

		for (unsigned int l_firstIndex = 0; l_firstIndex < size; l_firstIndex++)
		{
			m_gridValues.push_back(std::vector<T>());

			for (unsigned int l_secondIndex = 0; l_secondIndex < size; l_secondIndex++)
			{
				T t_toBeAdded;

				t_fileReader >> t_toBeAdded;

				m_gridValues[l_firstIndex].push_back(t_toBeAdded);
			}
		}

		m_size = size;
	}

	else
	{
		std::cout << "Error in ParseGrid() in Grid2D: t_fileReader could not open filename.\n";
	}
}

/*
*********
TRIANGULARGRID
*********
*/

// CONSTRUCTORS

template<class T>
TriangularGrid<T>::TriangularGrid() : Grid2D<T>()
{

}

template<class T>
TriangularGrid<T>::TriangularGrid(std::string const& filename, unsigned int size) : Grid2D<T>()
{
	m_size = size;

	ParseGrid(filename, size);
}

// METHODS

template<class T>
unsigned int TriangularGrid<T>::FindLongestPath()
{
	unsigned int t_longestPath = 0;

	std::vector<std::vector<T>> t_pathLengths = m_gridValues;

	for (unsigned int l_firstIndex = 1; l_firstIndex < m_size; l_firstIndex++)
	{
		// Deal with edge cases first

		t_pathLengths[l_firstIndex][0] += t_pathLengths[l_firstIndex - 1][0];
		t_pathLengths[l_firstIndex][l_firstIndex] += t_pathLengths[l_firstIndex - 1][l_firstIndex - 1];

		// Deal with general case

		for (unsigned int l_secondIndex = 1; l_secondIndex <= l_firstIndex - 1; l_secondIndex++)
		{
			t_pathLengths[l_firstIndex][l_secondIndex]
				= t_pathLengths[l_firstIndex - 1][l_secondIndex] > t_pathLengths[l_firstIndex - 1][l_secondIndex - 1]
				? t_pathLengths[l_firstIndex - 1][l_secondIndex] + t_pathLengths[l_firstIndex][l_secondIndex]
				: t_pathLengths[l_firstIndex - 1][l_secondIndex - 1] + t_pathLengths[l_firstIndex][l_secondIndex];
		}
	}

	// The longest path is equal to the largest entry in the final row of t_pathLengths

	for (unsigned int l_index = 0; l_index < m_size; l_index++)
	{
		if (t_pathLengths[m_size - 1][l_index] > t_longestPath)
		{
			t_longestPath = t_pathLengths[m_size - 1][l_index];
		}
	}

	return t_longestPath;
}

template<class T>
void TriangularGrid<T>::ParseGrid(std::string const& filename, unsigned int size)
{
	std::ifstream t_fileReader;

	t_fileReader.open(filename);

	if (t_fileReader.is_open())
	{
		for (unsigned int l_firstIndex = 0; l_firstIndex < size; l_firstIndex++)
		{
			m_gridValues.push_back(std::vector<unsigned int>());

			for (unsigned int l_secondIndex = 0; l_secondIndex <= l_firstIndex; l_secondIndex++)
			{
				unsigned int t_nextInput = 0;

				t_fileReader >> t_nextInput;

				m_gridValues[l_firstIndex].push_back(t_nextInput);
			}
		}

		m_size = size;
	}

	else
	{
		std::cout << "Error in ParseGrid() in TriangularGrid: file could not be opened.\n";
	}
}

// OPERATOR OVERLOADS

template<class U>
std::ostream& operator<< (std::ostream& output, TriangularGrid<U> const& grid)
{
	for (unsigned int l_firstIndex = 0; l_firstIndex < grid.m_size; l_firstIndex++)
	{
		for (unsigned int l_secondIndex = 0; l_secondIndex <= l_firstIndex; l_secondIndex++)
		{
			output << grid.m_gridValues[l_firstIndex][l_secondIndex] << " ";
		}

		output << "\n";
	}

	return output;
}