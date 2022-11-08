#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int a = i;
        while (a)
        {
            if (a % 10 == m)
                ans++;
            a /= 10;
        }
    }
    cout << ans;
}