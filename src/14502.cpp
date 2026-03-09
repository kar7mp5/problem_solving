// 1707
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int N, M;

void print_graph(int graph[][8]) {
    cout << "================" << '\n';
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}

void copy_graph(int src[][8], int dst[][8]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            dst[i][j] = src[i][j];
        }
    }
}

void spread_virus(int graph[][8], int x, int y) {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (graph[nx][ny] != 0) continue;

        graph[nx][ny] = 2;
        spread_virus(graph, nx, ny);
    }
}

int count_safe(int graph[][8]) {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (graph[i][j] == 0)
                ++cnt;
        }
    }
    return cnt;
}

int dist = 0;
void place_walls(int graph[][8], int placed) {
    if (placed == 3) {
        int temp[8][8];
        copy_graph(graph, temp);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (temp[i][j] == 2) {
                    spread_virus(temp, i, j);
                }
            }
        }

        dist = max(dist, count_safe(temp));
        return;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (graph[i][j] == 0) {
                graph[i][j] = 1;
                place_walls(graph, placed + 1);
                graph[i][j] = 0;
            }
        }
    }
}

int main() {
    int x, y;
    int graph[8][8];
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> graph[i][j];
        }
    }

    place_walls(graph, 0);

    cout << dist << '\n';

    return 0;
}