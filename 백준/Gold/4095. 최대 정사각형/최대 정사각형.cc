#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        int a[1001][1001] = {0,}, dp[1001][1001] = {0,};
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == 0) {
                    continue;
                }
                int mi = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = mi;
                if (a[i - mi][j - mi]) {
                    dp[i][j]++;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << '\n';
    }
}
