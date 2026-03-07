// 1707
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K;
    cin >> K;
    for (int t = 0; t < K; ++t) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> graph(V+1, vector<int>(V+1));

        // Insert nodes
        int u, v;
        for (int i = 0; i < E; ++i) {
            cin >> u >> v;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        int tmp;
        for (int i = 1; i <= V; ++i) {
            tmp = 0;
            for (int j = 1; j <= V; ++j) {
                if (graph[i][j] == 1) {
                    ++tmp;
                    if (tmp == 3) {
                        cout << "NO";
                        return 0;
                    }
                }
            }
        }
        cout << "YES";
    }
    return 0;
}
