#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> l, r;
pair<int, int> ans[100001];
int inp[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		inp[i] = a;

		while (!l.empty() && a >= l.top().first)
		{
			l.pop();
		}
		if (!l.empty())
		{
			ans[i].second = l.top().second;
		}
		l.push({a, i});
		ans[l.top().second].first += l.size() - 1;
	}

	for (int i = n; i >= 1; i--)
	{

		while (!r.empty() && inp[i] >= r.top().first)
		{
			r.pop();
		}
		if (!r.empty())
		{
			if (ans[i].second == 0 || abs(i - ans[i].second) > abs(i - r.top().second))
				ans[i].second = r.top().second;
		}
		r.push({inp[i], i});
		ans[r.top().second].first += r.size() - 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (ans[i].first == 0)
		{
			cout << ans[i].first << '\n';
			continue;
		}
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
}