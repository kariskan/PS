#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
long long a[100000], n, m;

bool query(long long mid)
{
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        res += mid / a[i];
    }
    return m <= res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long start = 0, end = *min_element(a, a + n) * m;
    long long mid = (start + end) / 2, ans = LLONG_MAX;
    while (start <= end)
    {
        mid = (start + end) / 2;

        bool res = query(mid);

        if (res)
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << ans;
}