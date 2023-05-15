#include <iostream>
#include <vector>
using namespace std;

int map[201][201];
vector<int> v;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    continue;
                }
                if (map[i][k] && map[k][j]) {
                    if (map[i][j] == 0) {
                        map[i][j] = map[i][k] + map[k][j];
                    } else {
                        map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
                    }
                }
            }
        }
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int minSum = 2000000000, ans;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j < v.size(); j++) {
            sum = max(sum, map[v[j]][i] + map[i][v[j]]);
        }
        if (minSum > sum) {
            minSum = sum;
            ans = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j < v.size(); j++) {
            sum = max(sum, map[v[j]][i] + map[i][v[j]]);
        }
        if (sum == minSum) {
            cout << i << ' ';
        }
    }
}