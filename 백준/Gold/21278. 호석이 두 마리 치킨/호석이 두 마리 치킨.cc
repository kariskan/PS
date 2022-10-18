#include <iostream>
using namespace std;

int map[101][101];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j) continue;
                if (map[i][k] && map[k][j])
                {
                    if (map[i][j] == 0 || map[i][j] > map[i][k] + map[k][j])
                        map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }

    int ans = -1;
    int ans1, ans2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int t = 0;
            for (int k = 1; k <= n; k++)
            {
                t += min(map[k][i], map[k][j]) * 2;
            }
            if (ans == -1 || ans > t)
            {
                ans1 = i;
                ans2 = j;
                ans = t;
            }
        }
    }
    cout << ans1 << ' ' << ans2 << ' ' << ans;
}