// 1707
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int& start, vector<vector<int>>& graph, vector<int>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next: graph[cur]) {
            if (visited[next] == 0) {
                visited[next] = -visited[cur];
                q.push(next);
            }
            else if (visited[next] == visited[cur]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int K;
    cin >> K;
    while(K--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> graph(V+1);
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> visited(V+1, 0);
        bool isBipartite = true;
        for (int i = 1; i <= V; ++i) {
            if (visited[i] == 0) {
                if (!bfs(i, graph, visited)) {
                    isBipartite = false;
                    break;
                }
            }
        }

        cout << (isBipartite ? "YES" : "NO") << '\n';
    }

    return 0;
}
