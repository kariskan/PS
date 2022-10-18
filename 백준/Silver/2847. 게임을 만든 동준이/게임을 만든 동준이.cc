#include <iostream>
using namespace std;

int a[101];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;

    // i번째 수 a[i]는 최소 n은 돼야함
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] >= a[i + 1])
        {
            ans += abs(a[i] - a[i + 1]) + 1;
            a[i] = a[i + 1] - 1;
        }
    }

    cout << ans;
}