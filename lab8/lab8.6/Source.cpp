#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <ciso646>
#include <set>
#include <string>

class Element {
public:
	int value;
	std::vector<std::string> way;
	Element() : value(0), way{}{}
};

bool AvailableLeft(const std::vector<std::vector<Element>>& arr, const std::set<std::pair<int, int>>& used, const std::pair<int, int>& cur)
{
	int row = cur.first;
	int col = cur.second;
	if (col > 0 and arr[row][col - 1].value != -1 and (used.find({ row, col - 1 }) == used.end()))
	{
		return true;
	}
	return false;
}

bool AvailableRight(const std::vector<std::vector<Element>>& arr, const std::set<std::pair<int, int>>& used, const std::pair<int, int>& cur)
{
	int row = cur.first;
	int col = cur.second;
	if (col < arr[row].size() - 1 and arr[row][col + 1].value != -1 and (used.find({ row, col + 1 }) == used.end()))
	{
		return true;
	}
	return false;
}

bool AvailableUp(const std::vector<std::vector<Element>>& arr, const std::set<std::pair<int, int>>& used, const std::pair<int, int>& cur)
{
	int row = cur.first;
	int col = cur.second;
	if (row > 0 and arr[row - 1][col].value != -1 and (used.find({ row - 1, col }) == used.end()))
	{
		return true;
	}
	return false;
}

bool AvailableDown(const std::vector<std::vector<Element>>& arr, const std::set<std::pair<int, int>>& used, const std::pair<int, int>& cur)
{
	int row = cur.first;
	int col = cur.second;
	if (row < arr.size() - 1 and arr[row + 1][col].value != -1 and (used.find({ row + 1, col }) == used.end()))
	{
		return true;
	}
	return false;
}

int bfs(std::vector < std::vector < Element > >& arr, const std::pair<int, int>& start, const std::pair<int, int>& finish)
{
	std::queue<std::pair<int, int>> q;
	std::set<std::pair<int, int>> used;
	q.push(start);
	used.insert(start);
	while (!q.empty())
	{
		std::pair<int, int> cur = q.front();
		q.pop();
		int row = cur.first;
		int col = cur.second;
		if (cur == finish)
			break;
		if (AvailableLeft(arr, used, cur))
		{
			arr[row][col - 1].value = arr[row][col].value + 1;
			used.insert({ row, col - 1 });
			q.push({ row, col - 1 });
			arr[row][col - 1].way = arr[row][col].way;
			arr[row][col - 1].way.push_back("L");
		}
		if (AvailableRight(arr, used, cur))
		{
			arr[row][col + 1].value = arr[row][col].value + 1;
			used.insert({ row, col + 1 });
			q.push({ row, col + 1 });
			arr[row][col + 1].way = arr[row][col].way;
			arr[row][col + 1].way.push_back("R");
		}
		if (AvailableUp(arr, used, cur))
		{
			arr[row - 1][col].value = arr[row][col].value + 1;
			used.insert({ row - 1, col });
			q.push({ row - 1, col });
			arr[row - 1][col].way = arr[row][col].way;
			arr[row - 1][col + 1].way.push_back("U");
		}
		if (AvailableDown(arr, used, cur))
		{
			arr[row + 1][col].value = arr[row][col].value + 1;
			used.insert({ row + 1, col });
			q.push({ row + 1, col });
			arr[row + 1][col].way = arr[row][col].way;
			arr[row + 1][col].way.push_back("D");
		}
	}

	if (arr[finish.first][finish.second].value == 0)
		return -1;
	return arr[finish.first][finish.second].value;
}

int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int n, m;
	char ch;
	fin >> n >> m;
	std::vector<std::vector<Element>> arr(n, std::vector<Element>(m));
	std::pair<int, int> start;
	std::pair<int, int> finish;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			fin >> ch;
			if (ch == 'S')
				start = { i, j };
			if (ch == 'T')
				finish = { i, j };
			if (ch == '#')
				arr[i][j].value = -1;
		}

	int answer = bfs(arr, start, finish);
	if (answer == -1)
	{
		fout << -1;
		fin.close();
		fout.close();
		return 0;
	}
	else
	{
		fout << answer << "\n";
		for (int i = 0; i < arr[finish.first][finish.second].way.size(); i++)
			fout << arr[finish.first][finish.second].way[i];
	}
	fin.close();
	fout.close();
	return 0;
}
