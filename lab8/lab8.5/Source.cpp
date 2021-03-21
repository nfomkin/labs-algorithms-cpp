#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>

void bfs(std::vector<std::vector<int>>& G, std::vector<int>& dst, std::vector<bool>& used, int start)
{

    std::queue <int> q;
    used[start] = true;
    dst[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto vertex : G[curr])
        {
            if (!used[vertex])
            {
                used[vertex] = true;
                dst[vertex] = dst[curr] + 1;
                q.push(vertex);
            }
        }
    }
}
int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("pathbge1.in");
    fout.open("pathbge1.out");
    int n, m;
    int a, b;
    fin >> n >> m;

    std::vector<std::vector<int>> G(n + 1, std::vector<int>());
    std::vector <int> dst(n + 1, -1);
    std::vector <bool> used(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bfs(G, dst, used, 1);

    for (int i = 1; i < n + 1; i++)
        fout << dst[i] << " ";

    fin.close();
    fout.close();
    return 0;
}