#include <iostream>
#include <fstream>
using namespace std; 

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int n, m;
	fin >> n >> m;

	int** array = new int* [n];
	for (int i = 0; i < n; i++)
		array[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			array[i][j] = 0;

	int row, col;
	for (int i = 0; i < m; i++)
	{
		fin >> row >> col;
		array[row - 1][col - 1] = 1;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fout << array[i][j] << " ";
		}
		fout << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] array[i];
	delete[] array;
	fin.close();
	fout.close();
	return 0;
}