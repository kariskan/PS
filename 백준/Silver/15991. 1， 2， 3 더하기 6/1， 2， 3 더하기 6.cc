#include <iostream>
using namespace std;

long long dp[100001];

int main()
{
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 3;
    int mod = 1000000009;
    for (int i = 6; i <= 100000; i++)
    {
        dp[i] = (dp[i - 2] % mod + dp[i - 4] % mod + dp[i - 6] % mod) % mod;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}