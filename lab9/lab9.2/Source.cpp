#include <iostream>
#include <vector>
#include <fstream>
#include <string>


void Find_cycle(std::vector<std::vector<int>>& G, std::vector<char>& used, std::vector<int>& way, int start, std::string& ans, char color)
{
	used[start] = color;
	way.push_back(start);
	for (auto v : G[start])
	{
		if (used[v] == 'G')
		{
			ans = "YES";
			Find_cycle(G, used, way, v, ans, 'B');
		}
		else if (used[v] == 'W')
		{
			Find_cycle(G, used, way, v, ans, 'G');
		}
	}
	used[start] = 'B';
}
int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("cycle.in");
	fout.open("cycle.out");
	int n, m;
	fin >> n >> m;

	std::vector<std::vector<int>> G(n + 1, std::vector<int>());
	std::vector<char> used(n + 1, 'W');
	std::vector<int> way;
	std::string ans = "NO";
	int a, b;
	for (int i = 0; i < m; i++)
	{
		fin >> a >> b;
		G[a].push_back(b);
	}

	for (int i = 1; i < n + 1 and ans == "NO"; i++)
	{
		if (used[i] == 'W')
		{
			Find_cycle(G, used, way, i, ans, 'G');
		}
	}

	if (ans == "NO")
	{
		fout << "NO";
		fin.close();
		fout.close();
		return 0;
	}

	int start = 0, finish = way.size() - 1;
	for (int i = way.size() - 1; i > 0 and way[start] != way[finish]; i--)
	{
		finish = i;
		for (int j = i - 1; j >= 0; j--)
		{
			if (way[finish] == way[j])
			{
				start = j;
				break;
			}
		}
	}
	fout << ans << '\n';
	for (int i = start; i < finish; i++)
		fout << way[i] << " ";

	fin.close();
	fout.close();
	return 0;
}