#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<pair<int, int>>> v;

int maxDis, root1, ans, root2, now;

void go(int node, int pre, int sum)
{
	if (maxDis < sum)
	{
		maxDis = sum;
		root1 = node;
	}

	for (auto &i : v[node])
	{
		if (i.first != pre)
		{
			go(i.first, node, sum + i.second);
		}
	}
}

void go2(int node, int pre, int sum)
{
	if (maxDis < sum)
	{
		maxDis = sum;
		root2 = node;
	}

	for (auto &i : v[node])
	{
		if (i.first != pre)
		{
			go2(i.first, node, sum + i.second);
		}
	}
}

void go3(int node, int pre, int sum)
{
	if (now == root1 && node == root2)
		return;
	if (now == root2 && node == root1)
		return;
	ans = max(ans, sum);

	for (auto &i : v[node])
	{
		if (i.first != pre)
		{
			go3(i.first, node, sum + i.second);
		}
	}
}

int main()
{
	cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}

	go(1, 0, 0);
	maxDis = 0;
	go2(root1, 0, 0);
	now = root1;
	go3(root1, 0, 0);
	now = root2;
	go3(root2, 0, 0);

	cout << ans;
}