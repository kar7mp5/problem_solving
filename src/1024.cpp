// 1024
#include<iostream>
#include<vector>
using namespace std;

long long N; // <= 1'000'000'000
int L;

int main() {
    cin >> N >> L;
    for (int k = L; k <= 100; ++k) {
        int tmp = N - k*(k-1)/2;
        if (tmp < 0)
            continue;

        if (tmp % k == 0) {
            int start = tmp / k;
            for (int i = 0; i < k; ++i) {
                cout << start + i<< ' ';
            }
            return 0;
        }
    }
    cout << -1;

    return 0;
}