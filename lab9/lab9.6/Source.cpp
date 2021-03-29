#include <fstream>
#include <vector>
#include <algorithm>

void Topological_sort(std::vector<std::vector<int>>& G, std::vector<int>& sorted_vertexes, std::vector<bool>& used, int start)
{
	if (used[start])
		return;
	used[start] = true;
	for (auto neighbour : G[start])
	{
		Topological_sort(G, sorted_vertexes, used, neighbour);
	}
	sorted_vertexes.push_back(start);
}

int WhoIsWin(std::vector<std::vector<int>>& G, std::vector<int>& sorted_vertexes, std::vector<char>& position, int start)
{
	while (position[start] == '#')
	{
		int cur = sorted_vertexes.back();
		sorted_vertexes.pop_back();
		position[cur] = '-';
		for (auto neighbour : G[cur])
		{
			if (position[neighbour] == '-')
			{
				position[cur] = '+';
				break;
			}
		}
	}
	return 1 ? position[start] == '+' : 2;
}

int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("game.in");
	fout.open("game.out");
	int n, m, start;
	fin >> n >> m >> start;
	std::vector<std::vector<int>> G(n + 1, std::vector<int>());
	std::vector<char> position(n + 1, '#');
	std::vector<int> sorted_vertexes;
	std::vector<bool> used(n + 1, false);

	int a, b;
	for (int i = 0; i < m; i++)
	{
		fin >> a >> b;
		G[a].push_back(b);
	}

	for (int i = 1; i < n + 1; i++)
	{
		Topological_sort(G, sorted_vertexes, used, i);
	}
	std::reverse(sorted_vertexes.begin(), sorted_vertexes.end());

	if (WhoIsWin(G, sorted_vertexes, position, start) == 1)
	{
		fout << "First player wins";
	}
	else
		fout << "Second player wins";

	fin.close();
	fout.close();
	return 0;
}