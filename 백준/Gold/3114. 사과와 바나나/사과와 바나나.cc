#include <iostream>
using namespace std;

int n, m, map[1501][1501]; // map[i][j] > 0이면 사과, map[i][j] < 0이면 바나나
int dp[1501][1501]; // dp[i][j] = (i,j)에 도달했을 때 얻을 수 있는 각 나무의 합
int asum[1501][1501],
    bsum[1501][1501]; // sum[i][j] = j열의 i행 까지의 각 나무 누적합

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char a;
            int b;
            cin >> a >> b;
            asum[i][j] = asum[i - 1][j];
            bsum[i][j] = bsum[i - 1][j];
            if (a == 'A') {
                map[i][j] = b;
                asum[i][j] += b;
            } else {
                map[i][j] = -b;
                bsum[i][j] += b;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i][1] = asum[n][1] - asum[i][1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            // 왼쪽 위에서 오는 경우, 아래 사과나무 누적합과 위의 바나나 나무
            // 누적합
            dp[i][j] =
                dp[i - 1][j - 1] + (asum[n][j] - asum[i][j]) + (bsum[i - 1][j]);

            // 왼쪽에서 오는 경우, 아래 사과나무 누적합과 위의 바나나 나무
            // 누적합
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + (asum[n][j] - asum[i][j]) +
                                         (bsum[i - 1][j]));

            // 위에서 오는 경우, 사과나무의 누적합만 변하게 된다
            if (map[i][j] > 0) {
                // 현재 도달한 칸이 사과나무 일때는 위의 dp값에서 빼줘야 한다
                dp[i][j] = max(dp[i][j], dp[i - 1][j] - map[i][j]);
            } else {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
    }
    cout << dp[n][m];
}
