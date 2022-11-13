#include <iostream>
using namespace std;

long long dp[1001][1001], t;

int main()
{
    cin >> t;

    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;
    int mod = 1000000009;
    for (int i = 4; i <= 1000; i++)
    {
        for (int j = 2; j <= 1000; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 2][j - 1] % mod + dp[i - 3][j - 1] % mod) % mod;
        }
    }

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }
}