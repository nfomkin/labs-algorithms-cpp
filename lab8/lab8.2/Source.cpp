#include <iostream>
#include <fstream>
#include <ciso646>
#include <string>

std::string Check(int** array, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				if (array[i][j] == 1)
					return "NO";
			}
			else
			{
				if (array[i][j] != array[j][i])
					return "NO";
			}
		}
	return "YES";
}
int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int n;
	fin >> n;
	int** array = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			fin >> array[i][j];
		}
	fout << Check(array, n);

	for (int i = 0; i < n; i++)
		delete[] array[i];
	delete[] array;
	fin.close();
	fout.close();
	return 0;
}