#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::ifstream fin;
	std::ofstream fout;
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
	std::string answer = "NO";
	for (int i = 0; i < m; i++)
	{
		fin >> row >> col;
		if (array[row-1][col-1] == 0)
		{
			array[row-1][col-1] = 1;
			array[col-1][row-1] = 1;
		}
		else
		{
			answer = "YES";
			break;
		}
	}
	fout << answer;

	for (int i = 0; i < n; i++)
		delete[] array[i];
	delete[] array;
	fin.close();
	fout.close();
	return 0;
}