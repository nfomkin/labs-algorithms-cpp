#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int invert(int c)
{
	return (c == 1) ? 2 : 1;
}
void Bipartition_check(std::vector<std::vector<int>>& G, std::vector<int>& color, std::string& ans, int start, int c)
{
	color[start] = c;
	for (auto v : G[start])
	{
		if (color[v] == 0)
		{
			Bipartition_check(G, color, ans, v, invert(c));
		}
		else if (color[v] == color[start])
		{
			ans = "NO";
		}
	}
}


int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("bipartite.in");
	fout.open("bipartite.out");
	int n, m;
	fin >> n >> m;
	std::vector<std::vector<int>> G(n + 1, std::vector<int>());
	std::vector<int> color(n + 1, 0);
	std::string ans = "YES";

	int a, b;
	for (int i = 0; i < m; i++)
	{
		fin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	} 
	for (int i = 1; i < n + 1 and ans == "YES"; i++)
	{
		if (color[i] == 0)
			Bipartition_check(G, color, ans, i, 1);
	}

	fout << ans;
	fin.close();
	fout.close();
	return 0;
}