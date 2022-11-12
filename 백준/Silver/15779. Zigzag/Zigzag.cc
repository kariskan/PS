#include <iostream>
using namespace std;

int a[5000], n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = min(n, 2);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            if (!((a[j] > a[j - 1] && a[j - 1] < a[j - 2]) || (a[j] < a[j - 1] && a[j - 1] > a[j - 2])))
            {
                break;
            }
            ans = max(ans, j - i + 1);
        }
    }
    cout << ans;
}