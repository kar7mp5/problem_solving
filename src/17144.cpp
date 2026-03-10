// 17144
#include <iostream>
using namespace std;

int graph[51][51];

void print_graph(int graph[][51], int r, int c) {
    cout << "===============" << '\n';
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}

void spread_graph(int graph[][51], int r, int c) {
    int temp_graph[51][51] = {0};
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            if (graph[x][y] == -1) {
                temp_graph[x][y] = -1;
                continue;
            }

            if (graph[x][y] > 0) {
                int spread = graph[x][y] / 5;
                int cnt = 0;

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                    if (graph[nx][ny] == -1) continue;

                    temp_graph[nx][ny] += spread;
                    cnt++;
                }

                temp_graph[x][y] += graph[x][y] - spread * cnt;
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            graph[i][j] = temp_graph[i][j];
        }
    }
}

void air_purifier(int up, int down, int graph[][51], int r, int c) {
    // upper
    for (int i = up - 1; i > 0; --i) {
        graph[i][0] = graph[i - 1][0];
    }
    for (int j = 0; j < c - 1; ++j) {
        graph[0][j] = graph[0][j + 1];
    }
    for (int i = 0; i < up; ++i) {
        graph[i][c - 1] = graph[i + 1][c - 1];
    }
    for (int j = c - 1; j > 1; --j) {
        graph[up][j] = graph[up][j - 1];
    }
    graph[up][1] = 0;

    // lower
    for (int i = down + 1; i < r - 1; ++i) {
        graph[i][0] = graph[i + 1][0];
    }
    for (int j = 0; j < c - 1; ++j) {
        graph[r - 1][j] = graph[r - 1][j + 1];
    }
    for (int i = r - 1; i > down; --i) {
        graph[i][c - 1] = graph[i - 1][c - 1];
    }
    for (int j = c - 1; j > 1; --j) {
        graph[down][j] = graph[down][j - 1];
    }
    graph[down][1] = 0;

    graph[up][0] = -1;
    graph[down][0] = -1;
}

int main() {
    int R, C, T;
    cin >> R >> C >> T;

    int up = -1, down = -1;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < R; ++i) {
        if (graph[i][0] == -1) {
            up = i;
            down = i + 1;
            break;
        }
    }

    for (int i = 0; i < T; ++i) {
        spread_graph(graph, R, C);
        air_purifier(up, down, graph, R, C);
    }

    int result = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (graph[i][j] > 0) {
                result += graph[i][j];
            }
        }
    }

    cout << result << '\n';

    return 0;
}