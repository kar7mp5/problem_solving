// 2263
#include <iostream>
#include <vector>
using namespace std;

vector<int> inorder, postorder, position, preorder;

void solve(int inLeft, int inRight, int postLeft, int postRight) {
    if (inLeft > inRight || postLeft > postRight) return;

    int root = postorder[postRight];
    cout << root << ' ';

    int root_index = position[root];
    int left_size = root_index - inLeft;
    // cout << left_size;

    // left
    solve(inLeft, root_index-1, postLeft, postLeft + left_size - 1);

    // right
    solve(root_index+1, inRight, postLeft + left_size, postRight-1);
}

int main() {
    int n;
    cin >> n;

    inorder.resize(n);
    postorder.resize(n);
    position.resize(n+1);
    preorder.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
        position[inorder[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }

    solve(0, n-1, 0, n-1);

    // for (int i = 1; i <= n; ++i) {
    //     cout << inorder[i] << ' ';
    // }

    return 0;
}