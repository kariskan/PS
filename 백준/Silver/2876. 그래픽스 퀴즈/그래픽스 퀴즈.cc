#include <iostream>

using namespace std;

int n, a, b;
int ar[100001][6];
int ans, ansi;

int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        ar[i][a] = ar[i - 1][a] + 1;
        if (a != b)
        {
            ar[i][b] = ar[i - 1][b] + 1;
        }
    }

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ans < ar[j][i])
            {
                ans = ar[j][i];
                ansi = i;
            }
        }
    }
    cout << ans << " " << ansi << '\n';
}