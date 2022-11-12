#include <iostream>
using namespace std;

long long n, dp1[100001], dp2[100001]; // 홀, 짝

int main()
{
    cin >> n;

    dp1[0] = 1;
    dp1[1] = 1;
    dp1[2] = 1;
    dp2[2] = 1;
    dp1[3] = 2;
    dp2[3] = 2;
    dp1[4] = 3;
    dp2[4] = 4;
    int mod = 1000000009;
    for (int i = 5; i <= 100000; i++)
    {
        dp1[i] = (dp2[i - 1] % mod + dp2[i - 2] % mod + dp2[i - 3] % mod) % mod;
        dp2[i] = (dp1[i - 1] % mod + dp1[i - 2] % mod + dp1[i - 3] % mod) % mod;
    }

    while (n--)
    {
        int a;
        cin >> a;
        cout << dp1[a] << ' ' << dp2[a] << '\n';
    }
}