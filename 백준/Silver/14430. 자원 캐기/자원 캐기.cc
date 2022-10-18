#include <iostream>
using namespace std;

int map[301][301], dp[301][301];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (map[i][j] == 1 ? 1 : 0);
        }
    }

    cout << dp[n][m];
}