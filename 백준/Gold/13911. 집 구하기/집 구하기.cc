#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> v;
vector<int> mac, star;
int n, e, mc, md, sc, sd;
int house[10001];

vector<int> dijk(int start)
{
    vector<int> dis(n + 3, 987654321);
    priority_queue<pair<int, int>> pq;

    pq.push({0, start});
    dis[start] = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (dis[node] < cost)
        {
            continue;
        }

        for (auto &i : v[node])
        {
            int nxCost = cost + i.second;
            if (dis[i.first] > nxCost)
            {
                dis[i.first] = nxCost;
                pq.push({-nxCost, i.first});
            }
        }
    }
    return dis;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;
    v.resize(n + 3);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    cin >> mc >> md;
    for (int i = 0; i < mc; i++)
    {
        int a;
        cin >> a;
        house[a] = -1;
        v[n + 1].push_back({a, 0});
    }
    cin >> sc >> sd;
    for (int i = 0; i < sc; i++)
    {
        int a;
        cin >> a;
        house[a] = -1;
        v[n + 2].push_back({a, 0});
    }

    vector<int> mDis = dijk(n + 1);
    vector<int> sDis = dijk(n + 2);
    int ans = 987654321;
    for (int i = 1; i <= n; i++)
    {
        if (house[i] == -1)
        {
            continue;
        }
        if (mDis[i] <= md && sDis[i] <= sd)
        {
            ans = min(ans, mDis[i] + sDis[i]);
        }
    }

    if (ans == 987654321)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}