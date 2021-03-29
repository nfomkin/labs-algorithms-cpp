#include <fstream>
#include <vector>


int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int n, m;
	fin >> n >> m;
	std::vector<int> G(n + 1, 0);

	int a, b;
	for (int i = 0; i < m; i++)
	{
		fin >> a >> b;
		G[a]++;
		G[b]++;
	}

	for (int i = 1; i < n + 1; i++)
	{
		fout << G[i] << " ";
	}

	fin.close();
	fout.close();
	return 0;
}