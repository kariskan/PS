#include <iostream>
using namespace std;

/* 4 3
1 2 3 4
2 3 4 5
3 4 5 6
4 5 6 7
2 2 3 4
3 4 3 4
1 1 4 4*/

int n, m, a[1025][1025], s[1025][1025];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] += a[i][j] + s[i - 1][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        int sum = 0;
        for (int j = a2; j <= a4; j++) {
            sum += s[a3][j] - s[a1 - 1][j];
        }
        cout << sum << '\n';
    }
}