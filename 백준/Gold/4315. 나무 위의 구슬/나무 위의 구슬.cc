#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> v;
int n, ball[10001], parent[10001];
long long ans;

void go(int node)
{
	for (auto &i : v[node])
	{
		go(i);
	}
	ball[parent[node]] += (ball[node] - 1);
	ans += abs(ball[node] - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n, n != 0)
	{
		v.clear();
		v.resize(n + 1);
		memset(ball, 0, sizeof(ball));
		memset(parent, 0, sizeof(parent));
		ans = 0;

		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			cin >> ball[i];
			cin >> a;
			for (int j = 0; j < a; j++)
			{
				int b;
				cin >> b;
				parent[b] = i;
				v[i].push_back(b);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (parent[i] == 0)
			{
				go(i);
			}
		}
		cout << ans << '\n';
	}
}