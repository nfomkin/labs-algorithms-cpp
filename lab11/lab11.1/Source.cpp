#include <fstream>
#include <vector>
#include <algorithm>
#include <ciso646>
#include <limits.h>

long long inf = LLONG_MAX;

int Find_Min(std::vector<bool>& used, std::vector <long long> & distance)
{
	long long min = inf;
	int min_index = 0;
	for (int i = 1; i < distance.size(); i++)
	{
		if (!used[i] and distance[i] < min)
		{
			min = distance[i];
			min_index = i;
		}
	}
	return min_index;
}

long long Dijkstra(std::vector<std::vector<int>>& G, std::vector<bool>& used, std::vector<long long>& distance, int start, int finish)
{
	distance[start] = 0;
	for (int i = 1; i < G.size() - 1; i++)
	{
		int min;
		if (not(min = Find_Min(used, distance)))
		{
			break;
		}
		used[min] = true;
		for (int j = 1; j < G.size(); j++)
		{
			if (G[min][j] != -1 and G[min][j] + distance[min] < distance[j])
				distance[j] = G[min][j] + distance[min];
		}
	}
	if (distance[finish] == inf)
		return -1;
	return distance[finish];
}

int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("pathmgep.in");
	fout.open("pathmgep.out");
	int n, start, finish;
	fin >> n >> start >> finish;
	std::vector<std::vector<int>> G(n + 1, std::vector<int>(n + 1, -1));
	std::vector<bool> used(n + 1, false);
	std::vector<long long> distance(n + 1, inf);

	int value;
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
		{
			fin >> value;
			G[i][j] = value;
		}

	fout << Dijkstra(G, used, distance, start, finish);
	fin.close();
	fout.close();
	return 0;
}
