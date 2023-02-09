#include <iostream>
#include <set>
using namespace std;
set<pair<int, int>> se;
pair<int, int> x[4][4] = {
	{{0, 0}, {0, 1}, {1, 0}, {1, 1}},
	{{0, 0}, {0, 1}, {-1, 0}, {-1, 1}},
	{{0, 0}, {0, -1}, {-1, 0}, {-1, -1}},
	{{0, 0}, {1, 0}, {0, -1}, {1, -1}}};
pair<int, int> inp[500000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
	{
		int c1, c2;
		cin >> c1 >> c2;
		inp[i] = {c1, c2};
		se.insert({c1, c2});
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int ok = 1;
			for (int k = 0; k < 4; k++)
			{
				if (!se.count({inp[i].first + x[j][k].first * a, inp[i].second + x[j][k].second * b}))
				{
					ok = 0;
					break;
				}
			}
			if (ok)
			{
				ans++;
			}
		}
	}

	cout << ans / 4;
}