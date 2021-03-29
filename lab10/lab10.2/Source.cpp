#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void dist(vector<pair<int, int>>& G, vector<double>& distance, vector<bool>& used, int v)
{
	int a, b;
	double c;
	for (int i = 0; i < G.size(); i++)
	{
		if (!used[i])
		{
			a = G[v].first - G[i].first;
			b = G[v].second - G[i].second;
			c = sqrt(pow(a, 2) + pow(b, 2));
			if (c < distance[i])
			{
				distance[i] = c;
			}
		}
	}
}

int find_min(const vector<double>& distance, const vector<bool>& used)
{
	double min = 30000;
	int index_min = 0;
	for (int i = 0; i < distance.size(); i++)
	{
		if (!used[i] and distance[i] < min)
		{
			min = distance[i];
			index_min = i;
		}
	}
	return index_min;
}
double Prima(vector<pair<int, int>>& G, vector<bool>& used, vector<double>& distance)
{
	double weight = 0;
	distance[0] = 0;
	for (int i = 0; i < G.size(); i++)
	{
		int vertex = find_min(distance, used);
		used[vertex] = true;
		weight += distance[vertex];
		dist(G, distance, used, vertex);
	}
	return weight;
}

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("spantree.in");
	fout.open("spantree.out");
	int n;
	double inf = 30000;
	fin >> n;
	vector<pair<int, int>> G(n);
	vector<bool> used(n, false);
	vector<double> distance(n, inf);
	int x, y;

	for (int i = 0; i < n; i++)
	{
		fin >> x >> y;
		G[i] = { x, y };
	}

	fout << std::setprecision(15) << Prima(G, used, distance);
	fin.close();
	fout.close();
	return 0;
}