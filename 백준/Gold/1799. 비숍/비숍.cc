#include <iostream>
using namespace std;

int n, ans[2], map[10][10], lo[20], ro[20];

void go(int r, int c, int cnt, int color)
{
    if (c >= n)
    {
        r++;
        if (c % 2 == 0)
        {
            c = 1;
        }
        else
        {
            c = 0;
        }
    }
    if (r >= n)
    {
        ans[color] = max(ans[color], cnt);
        return;
    }

    if (map[r][c] && !lo[c - r + n - 1] && !ro[c + r])
    {
        lo[c - r + n - 1] = 1;
        ro[c + r] = 1;
        go(r, c + 2, cnt + 1, color);
        lo[c - r + n - 1] = 0;
        ro[c + r] = 0;
    }
    go(r, c + 2, cnt, color);
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    go(0, 0, 0, 0);
    go(0, 1, 0, 1);

    cout << ans[0] + ans[1];
}