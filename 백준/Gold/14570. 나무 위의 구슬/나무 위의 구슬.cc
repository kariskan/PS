#include <iostream>
#include <vector>
using namespace std;

int n;
pair<int, int> a[200001];
int leaf[200001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int u, v;
		cin >> u >> v;

		a[i].first = u;
		a[i].second = v;

		if (u == -1 && v == -1)
		{
			leaf[i] = 1;
		}
	}

	long long k;
	cin >> k;
	int now = 1;

	while (k)
	{
		if (leaf[now])
		{
			break;
		}
		else if (a[now].first == -1) now = a[now].second;
		else if (a[now].second == -1) now = a[now].first;
		else if (k % 2 == 0)
		{
			k /= 2;
			now = a[now].second;
		}
		else
		{
			k = k / 2 + 1;
			now = a[now].first;
		}
	}
	
	cout << now;
}