#include <fstream>
#include <set>
#include <vector>
#include <ciso646>
#include <stack>

void dfs1(std::vector<std::vector<int>>& G, std::vector<bool>& used, std::stack<int>& stack, int start)
{
	if (used[start])
		return;
	used[start] = true;
	for (auto v : G[start])
	{
		dfs1(G, used, stack, v);
	}
	stack.push(start);
}

void dfs2(std::vector<std::vector<int>>& G, std::vector<int>& res, std::vector<bool>& used, int start, int comp)
{
	used[start] = true;
	res[start] = comp;
	for (auto v : G[start])
	{
		if (!used[v])
			dfs2(G, res, used, v, comp);
	}
}

int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("cond.in");
	fout.open("cond.out");

	int n, m;
	fin >> n >> m;
	std::vector<std::vector<int>> G1(n + 1, std::vector<int>());
	std::vector<std::vector<int>> G2(n + 1, std::vector<int>());
	std::stack<int> stack;
	std::vector<bool> used(n + 1, false);
	std::vector<int> result(n + 1);

	int a, b;
	for (int i = 0; i < m; i++)
	{
		fin >> a >> b;
		G1[a].push_back(b);
		G2[b].push_back(a);
	}

	for (int i = 1; i < n + 1; i++)
	{
		dfs1(G1, used, stack, i);
	}

	used.assign(n + 1, false);
	int comp = 0;
	while (!stack.empty())
	{
		if (!used[stack.top()])
		{
			comp++;
			dfs2(G2, result, used, stack.top(), comp);
		}
		stack.pop();
	}

	fout << comp << '\n';
	for (int i = 1; i < result.size(); i++)
		fout << result[i] << " ";

	fin.close();
	fout.close();
	return 0;
}