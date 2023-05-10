#include <iostream>
using namespace std;

int map[101][101];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a; j <= c; j++) {
            for (int k = b; k <= d; k++) {
                map[j][k]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (map[i][j] > m) {
                ans++;
            }
        }
    }
    cout << ans;
}