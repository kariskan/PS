#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

long long n, m, k;						   // n = 강의동의 수, m = 공사구간의 수, k = 가진 돌의 수
int parent[1000002];					   // 부모 노드를 저장하는 배열
vector<pair<long long, pair<int, int>>> v; // 가중치, {정점1, 정점2} 인접리스트
set<pair<int, int>> se;					   // 이어질 수 없는 간선을 저장하는 자료구조

int Find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	parent[a] = b;
}

void Input()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		long long c;
		cin >> c;
		v.push_back({c, {i, n + 1}}); // i번과 와우도를 잇는 간선
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		se.insert({min(a, b), max(a, b)}); // 공사중인 간선을 판단
	}
	for (int i = 1; i <= n; i++) // 공사중이지 않는 간선의 가중치를 0으로 설정
	{
		if (i == n)
		{
			if (!se.count({1, n}))
			{
				v.push_back({0, {1, n}});
			}
		}
		else
		{
			if (!se.count({i, i + 1}))
			{
				v.push_back({0, {i, i + 1}});
			}
		}
	}
}

void Init()
{
	for (int i = 1; i <= n + 1; i++)
	{
		parent[i] = i;
	}
}

void Solve()
{
	Init();
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		long long cost = v[i].first;
		int p1 = Find(v[i].second.first);
		int p2 = Find(v[i].second.second);
		if (p1 != p2 && k >= cost) // 부모 정점이 다르고, 해당 다리를 이을 수 있으면
		{
			Union(p1, p2); // 잇는다
			k -= cost;
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (Find(i) != Find(i + 1)) // 이어져있지 않은 간선이 있으면 NO
		{
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solve();
}