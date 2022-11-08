#include <iostream>
using namespace std;
int dp[11];
int main()
{
    int n, m;
    cin >> n >> m;
    dp[0] = n;
    for (int i = 1; i <= 10; i++)
    {
        if (i - 1 >= 0)
        {
            dp[i] = max(dp[i], (int)(dp[i - 1] * 1.05));
        }
        if (i - 3 >= 0)
        {
            dp[i] = max(dp[i], (int)(dp[i - 3] * 1.20));
        }
        if (i - 5 >= 0)
        {
            dp[i] = max(dp[i], (int)(dp[i - 5] * 1.35));
        }
    }
    
    cout << dp[m];
}