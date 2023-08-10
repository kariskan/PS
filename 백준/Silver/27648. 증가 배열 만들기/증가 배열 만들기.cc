#include <iostream>
using namespace std;

int n, m, k, map[1000][1000];

bool range(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

int main() {
    cin >> n >> m >> k;
    if (n + m - 1 > k) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << num + j << ' ';
        }
        num++;
        cout << '\n';
    }
}