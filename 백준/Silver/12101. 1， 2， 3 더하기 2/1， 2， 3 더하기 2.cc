#include <iostream>
#include <string>
using namespace std;

int n, cnt, m;

void go(int sum, string s)
{
    if (sum > n)
    {
        return;
    }
    if (sum == n)
    {
        cnt++;
        if (cnt == m)
        {
            cout << s;
            exit(0);
        }
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        string t = s;
        if (s.empty())
            t = to_string(i);
        else
            t += "+" + to_string(i);
        go(sum + i, t);
    }
}

int main()
{
    cin >> n >> m;

    go(0, "");
    cout << -1;
}