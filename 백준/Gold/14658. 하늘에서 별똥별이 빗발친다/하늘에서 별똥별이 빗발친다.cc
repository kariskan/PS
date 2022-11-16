#include <iostream>
using namespace std;

int n, m, l, k;
pair<int, int> a[500000];

pair<int, int> getLeftTop(pair<int, int> coor, int d)
{
    return {coor.first - d, coor.second};
}

bool check(pair<int, int> leftTop, pair<int, int> coor)
{
    return coor.first >= leftTop.first && coor.first <= leftTop.first + l && coor.second >= leftTop.second && coor.second <= leftTop.second + l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> l >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            pair<int, int> leftTop = {a[i].first, a[j].second};
            int cnt = 0;
            for (int K = 0; K < k; K++)
            {
                if (check(leftTop, a[K]))
                {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }

    cout << k - ans;
}