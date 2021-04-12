#include <iostream>
#include <vector>
#include <fstream>
#include <limits.h>
#include <ciso646>

int inf = INT16_MAX;

void Floyd(std::vector<std::vector<int>>& G)
{
	int n = G.size();
	for (int k = 1; k < n; k++)
		for (int i = 1; i < n; i++)
			for (int j = 1; j < n; j++)
			{
				if (i == j or G[i][k] == inf or G[k][j] == inf)
					continue;
				G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);
			}
}

int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("pathsg.in");
	fout.open("pathsg.out");
	int n, m;
	fin >> n >> m;
	std::vector<std::vector<int>> G(n + 1, std::vector<int>(n + 1, inf));
	int a, b, weight;
	for (int i = 1; i < m + 1; i++)
	{
		fin >> a >> b >> weight;
		G[a][b] = weight;
	}

	for (int i = 1; i < n + 1; i++)
		G[i][i] = 0;

	Floyd(G);
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
			fout << G[i][j] << " ";
		fout << std::endl;
	}
	fin.close();
	fout.close();
	return 0;
}