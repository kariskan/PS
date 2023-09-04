#include <iostream>
using namespace std;

struct point {
    long long x;
    long long y;
    long long cost;
};

long long n, x, y;
long long dx[5] = {0, 0, 1, -1, 0};
long long dy[5] = {1, -1, 0, 0, 0};
pair<long long, long long> inp[100001];
point dp[100001][5];

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> inp[i].first >> inp[i].second;
    }
    for (int i = 0; i < 5; i++) {
        long long nx = inp[1].first + dx[i];
        long long ny = inp[1].second + dy[i];
        dp[1][i] = {nx, ny, abs(nx - x) + abs(ny - y)};
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            dp[i][j] = {inp[i].first + dx[j], inp[i].second + dy[j],
                        1000000000000000};
            for (int k = 0; k < 5; k++) {
                dp[i][j].cost =
                    min(dp[i][j].cost, dp[i - 1][k].cost +
                                           abs(dp[i - 1][k].x - dp[i][j].x) +
                                           abs(dp[i - 1][k].y - dp[i][j].y));
            }
        }
    }
    
    long long ans = 1000000000000000;
    for (int i = 0; i < 5; i++) {
        ans = min(ans, dp[n][i].cost);
    }
    cout << ans;
}