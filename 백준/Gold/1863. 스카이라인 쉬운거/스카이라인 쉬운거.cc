#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
pair<int, int> a[50000];

bool compare(pair<int, int> &p1, pair<int, int> &p2)
{
	return p1.first < p2.first;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n, compare);
	stack<int> st;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int height = a[i].second;

		while (!st.empty() && st.top() > height)
		{
			st.pop();
			ans++;
		}

		if (st.empty() || (!st.empty() && st.top() != height))
		{
			st.push(height);
		}
	}

	while (!st.empty() && st.top() != 0)
	{
		st.pop();
		ans++;
	}

	cout << ans;
}