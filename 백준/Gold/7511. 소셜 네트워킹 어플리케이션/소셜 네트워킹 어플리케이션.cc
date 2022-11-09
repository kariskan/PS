#include <iostream>
#include <cstring>
using namespace std;

int t, n, parent[1000001];

int Find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    parent[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Scenario " << i << ":\n";
        cin >> n;
        memset(parent, -1, sizeof(parent));
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            int fa = Find(a);
            int fb = Find(b);
            if (fa != fb)
            {
                Union(fa, fb);
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (Find(a) == Find(b))
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        cout<<'\n';
    }
}