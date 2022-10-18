#include <iostream>
using namespace std;

int a[101], parent[101];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < b; j++)
        {
            Union(j, j + 1);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == i)
            ans++;
    }
    cout << ans;
}