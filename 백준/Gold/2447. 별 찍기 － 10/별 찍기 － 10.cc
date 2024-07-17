#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <stack>
using namespace std;

int arr[3000][3000];

void go(int n, int x, int y) {
    if (n == 1) {
        arr[x][y] = 1;
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            go(n / 3, x + i * (n / 3), y + j * (n / 3));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    go(n, 0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}
