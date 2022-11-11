#include <iostream>
#include <algorithm>
using namespace std;
int a[52];
int main()
{
    int n, m, l;
    cin >> n >> m >> l;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    a[n++] = l;
    int left = 1, right = a[0];

    for (int i = 1; i < n; i++)
    {
        right = max(right, a[i] - a[i - 1]);
    }
    int ans = 0;
    for(int mid = 1; mid <= right; mid++) {
        int cursor = 0;
        int cnt = m;
        for (int i = 0; i < n; i++)
        {
            if (a[i] - cursor <= mid)
            {
                cursor = a[i];
                continue;
            }
            else
            {
                cnt--;
                if (cnt < 0)
                {
                    break;
                }
                cursor += mid;
                i--;
            }
        }
        if (cnt < 0)
        {
            continue;
        }
        else
        {
            cout << mid;
            return 0;
        }
    }

    cout << ans;
}