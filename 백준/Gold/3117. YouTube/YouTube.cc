#include <iostream>
#include <cstring>
using namespace std;

int n, k, m;
int p[100001][31], inp[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;

    for (int i = 1; i <= n; i++) {
        cin >> inp[i];
    }

    memset(p, -1, sizeof(p));
    for (int i = 1; i <= k; i++) {
        cin >> p[i][0];
    }

    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= k; j++) {
            if (p[p[j][i - 1]][i - 1] != -1) {
                p[j][i] = p[p[j][i - 1]][i - 1];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int target = m - 1;
        while (target) {
            for (int j = 30; j >= 0; j--) {
                if (target >= (1 << j)) {
                    inp[i] = p[inp[i]][j];
                    target -= (1 << j);
                    break;
                }
            }
        }
        cout << inp[i] << ' ';
    }
}