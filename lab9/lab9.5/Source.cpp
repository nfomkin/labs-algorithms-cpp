#include <fstream>
#include <vector>
#include <algorithm>

void Topological_sort(std::vector<std::vector<int>>& G, std::vector<bool>& used, std::vector<int>& sorted_vertexes, int start)
{
	if (used[start])
		return;
	used[start] = true;
	for (auto neighbour : G[start])
	{
		Topological_sort(G, used, sorted_vertexes, neighbour);
	}
	sorted_vertexes.push_back(start);
}

int CheckWay(std::vector<std::vector<int>>& G, std::vector<int>& sorted_vertexes)
{
	for (int i = 0; i < sorted_vertexes.size() - 1; i++)
	{
		std::vector<int> cur;
		cur = G[sorted_vertexes[i]];
		if (std::find(cur.begin(), cur.end(), sorted_vertexes[i + 1]) == cur.end())
			return 0;
	}
	return 1;
}
int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("hamiltonian.in");
	fout.open("hamiltonian.out");
	int n, m;
	fin >> n >> m;
	std::vector <std::vector<int>> G(n + 1, std::vector<int>());
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
		Topological_sort(G, used, sorted_vertexes, i);
	}
	std::reverse(sorted_vertexes.begin(), sorted_vertexes.end());

	if (CheckWay(G, sorted_vertexes))
	{
		fout << "YES";
	}
	else
		fout << "NO";
	fin.close();
	fout.close();
	return 0;
}