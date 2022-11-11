#include <iostream>
using namespace std;

int n, m, map[100][100];

pair<int, int> Find()
{
    pair<int, int> res = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1)
            {
                if (res.first + res.second < i + j)
                {
                    res = {i, j};
                }
            }
        }
    }
    return res;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    int ans = 0;
    while (1)
    {
        pair<int, int> p = Find();
        if (p.first == -1)
        {
            break;
        }
        ans++;
        for (int i = 0; i <= p.first; i++)
        {
            for (int j = 0; j <= p.second; j++)
            {
                map[i][j] = 1 - map[i][j];
            }
        }
    }

    cout << ans;
}