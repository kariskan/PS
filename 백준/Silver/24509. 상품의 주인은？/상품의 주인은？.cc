#include <iostream>
using namespace std;

int a[200001][4], vis[200001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < 4; j++) {
            cin >> a[num][j];
        }
    }
    for (int j = 0; j < 4; j++) {
        int res, ma = -1;
        for (int i = 1; i <= n; i++) {
            if (ma < a[i][j] && !vis[i]) {
                ma = a[i][j];
                res = i;
            }
        }
        vis[res] = 1;
        cout << res << ' ';
    }
}