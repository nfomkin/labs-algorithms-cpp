#include <iostream>
#include <map>
#include <fstream>
#include <set>
#include <vector>

int k;

void dfs(std::vector<std::vector<int>>& G, std::vector<bool>& used, std::vector<int>& result, int vertex)
{
	used[vertex] = true;
	result[vertex] = k + 1;
	for (auto element : G[vertex])
	{
		if (!used[element])
			dfs(G, used, result, element);
	}
}

int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("components.in");
	fout.open("components.out");
	int n, m;
	fin >> n >> m;

	std::vector<std::vector<int>> G(n + 1, std::vector<int>());
	std::vector<bool> used(n + 1, false);
	std::vector<int> result(n + 1, 0);
	int row, col;
	for (int i = 0; i < m; i++)
	{
		fin >> row >> col;
		G[row].push_back(col);
		G[col].push_back(row);
	}
	
	for (int i = 1; i < n + 1; i++)
	{
		if (!used[i])
		{
			dfs(G, used, result, i);
			k++;
		}
	}

	fout << k << std::endl;
	for (int i = 1; i < n + 1; i++)
		fout << result[i] << " ";

	fin.close();
	fout.close();
	return 0;
}