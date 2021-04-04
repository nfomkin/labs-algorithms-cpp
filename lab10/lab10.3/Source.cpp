#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int dsu_get(int v, vector<int>& tree_id) {
	return (v == tree_id[v]) ? v : (tree_id[v] = dsu_get(tree_id[v], tree_id));
}

void dsu_unite(int a, int b, vector<int>& tree_id) {
	a = dsu_get(a, tree_id);
	b = dsu_get(b, tree_id);
	if (rand() & 1)
		swap(a, b);
	if (a != b)
		tree_id[a] = b;
}

long long Kraskal(vector<pair<int, pair<int, int>>>& edges, vector<int>& tree_id)
{
	int number_of_edge = 0;
	long long weight = 0;
	while (number_of_edge != edges.size())
	{
		int w = edges[number_of_edge].first;
		int v1 = edges[number_of_edge].second.first;
		int v2 = edges[number_of_edge].second.second;
		if (dsu_get(v1, tree_id) != dsu_get(v2, tree_id))
		{
			dsu_unite(v1, v2, tree_id);
			weight += w;
		}
		number_of_edge++;
	}
	return weight;
}

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("spantree3.in");
	fout.open("spantree3.out");

	int n, m;
	fin >> n >> m;
	vector<int> tree_id(n + 1);
	vector < pair<int, pair<int, int>>> edges;
	int b, e, w;
	for (int i = 1; i < n + 1; i++)
	{
		tree_id[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		fin >> b >> e >> w;
		edges.push_back({ w, {b, e} });
	}
	sort(edges.begin(), edges.end());

	fout << Kraskal(edges, tree_id);

	fin.close();
	fout.close();
	return 0;
}