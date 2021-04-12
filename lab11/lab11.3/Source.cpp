#include <fstream>
#include <vector>
#include <ciso646>
#include <set>

int inf = INT32_MAX;

void Dijkstra(std::vector<std::vector<std::pair<int, int>>>& G, std::vector<int>& distance, int start)
{
    std::set<std::pair<int, int>> q;
    distance[start] = 0;
    q.insert({ distance[start], start });
    while (!q.empty())
    {
        int min_v = (*q.begin()).second;
        int min_weight = (*q.begin()).first;
        q.erase(q.begin());
        for (auto pair : G[min_v])
        {
            if (distance[min_v] + pair.second < distance[pair.first])
            {
                q.erase({ distance[pair.first], pair.first });
                distance[pair.first] = distance[min_v] + pair.second;
                q.insert({ distance[pair.first], pair.first });
            }
        }
    }
}

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("pathbgep.in");
    fout.open("pathbgep.out");
    int n, m;
    fin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> G(n + 1);
    std::vector<int> distance(n + 1, inf);

    int a, b, weight;
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b >> weight;
        G[a].push_back({ b, weight });
        G[b].push_back({ a, weight });
    }

    Dijkstra(G, distance, 1);

    for (int i = 1; i < n + 1; i++)
    {
        fout << distance[i] << " ";
    }

    fin.close();
    fout.close();
    return 0;
}