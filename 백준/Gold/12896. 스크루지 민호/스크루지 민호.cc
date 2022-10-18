#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<vector<int>> v;
int r, s;

void go(int node, int pre, int d)
{
    if (r < d)
    {
        r = d;
        s = node;
    }

    for (auto &i : v[node])
    {
        if (i != pre)
        {
            go(i, node, d + 1);
        }
    }
}

int main()
{
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    go(1, 0, 0);
    go(s, 0, 0);

    cout << (r + 1) / 2;
}