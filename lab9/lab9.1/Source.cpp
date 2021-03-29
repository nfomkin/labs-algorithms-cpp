#include <iostream>
#include <vector>
#include <fstream>

void dfs(std::vector<std::vector<int>>& G, std::vector<char>& used, std::vector<int>& ans, int vertex)
{
	used[vertex] = 'G';
	for (auto v : G[vertex])
	{
		if (used[v] == 'W')
			dfs(G, used, ans, v);
		else if (used[v] == 'G')
			used[0] = 'E';
	}
	used[vertex] = 'B';
	ans.push_back(vertex);
}
int main()
{
	std::ifstream fin;
	std::ofstream fout; 
	fin.open("topsort.in");
	fout.open("topsort.out");
	int n, m;
	fin >> n >> m;
	std::vector<std::vector<int>> G(n + 1, std::vector<int>());
	std::vector<char> used(n + 1, 'W');
	std::vector<int> ans;

	int v1, v2;
	for (int i = 0; i < m; i++)
	{
		fin >> v1 >> v2;
		G[v1].push_back(v2);
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (used[i] == 'W')
		{
			dfs(G, used, ans, i);
		}
	} 
	if (used[0] == 'E')
	{
		fout << -1;
		fin.close();
		fout.close();
		return 0;
	}
	else
	{
		for (int i = ans.size() - 1; i >= 0; i--)
			fout << ans[i] << " ";
	}
	fin.close();
	fout.close();
	return 0;
}