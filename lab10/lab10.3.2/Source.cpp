#include <vector>
#include <fstream>
#include <algorithm>

void join(std::vector<int>& id, std::vector<std::vector<int>>& elements_of_set, int x, int y)
{
	for (auto i : elements_of_set[x])
	{
		id[i] = y;
		elements_of_set[y].push_back(i);
	}
	elements_of_set[x] = {};
}

long long Kraskal(std::vector<std::pair<int, std::pair<int, int>>>& edges, std::vector<int>& id, std::vector<std::vector<int>>& elements_of_set)
{
	int count = 0;
	long long weight = 0;
	int number_of_edge = 0;
	while (count != id.size() - 2)
	{
		int v1 = edges[number_of_edge].second.first;
		int v2 = edges[number_of_edge].second.second;
		if (id[v1] != id[v2])
		{
			weight += edges[number_of_edge].first;
			int x = v1, y = v2;
			if (elements_of_set[x].size() > elements_of_set[y].size())
				std::swap(x, y);
			join(id, elements_of_set, x, y);
			count++;
		}
		number_of_edge++;
	}
	return weight;
}

int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("spantree3.in");
	fout.open("spantree3.out");
	int n, m;
	fin >> n >> m;
	std::vector<std::pair<int, std::pair<int, int>>> edges;
	std::vector<int> id(n + 1);
	std::vector<std::vector<int>> elements_of_set(n + 1, std::vector<int>());

	for (int i = 1; i < n + 1; i++)
	{
		id[i] = i;
		elements_of_set[i].push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		int b, e, w;
		fin >> b >> e >> w;
		edges.push_back({ w, {b, e} });
	}

	std::sort(edges.begin(), edges.end());

	fout << Kraskal(edges, id, elements_of_set);

	fin.close();
	fout.close();
	return 0;
}