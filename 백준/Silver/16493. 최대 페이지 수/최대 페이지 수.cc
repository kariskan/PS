#include <iostream>
using namespace std;

pair<int, int> a[20];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    int ans = 0;
    for (int i = 1; i < (1 << m); i++)
    {
        int daySum = 0, chapterSum = 0;
        for (int j = 0; j < m; j++)
        {
            if (i & (1 << j))
            {
                daySum += a[j].first;
                chapterSum += a[j].second;
            }
        }
        if (daySum <= n)
        {
            ans = max(ans, chapterSum);
        }
    }
    
    cout << ans;
}