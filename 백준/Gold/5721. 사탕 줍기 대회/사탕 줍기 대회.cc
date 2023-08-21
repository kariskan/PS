#include <iostream>
#include <vector>
using namespace std;

int n, m;
int x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        vector<vector<int>> v(n + 1, vector<int>(m + 1));
        vector<vector<int>> dp1(n + 1, vector<int>(m + 1));
        vector<vector<int>> dp2(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> v[i][j];
                dp1[i][j] = max(dp1[i][j - 2] + v[i][j], dp1[i][j - 1]);
            }
        }
        dp2[1][m] = dp1[1][m];
        for (int i = 2; i <= n; i++) {
            dp2[i][m] = max(dp2[i - 1][m], dp2[i - 2][m] + dp1[i][m]);
        }
        
        cout << dp2[n][m] << '\n';
    }
}