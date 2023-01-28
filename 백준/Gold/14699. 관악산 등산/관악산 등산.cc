#include <iostream>
#include <vector>
using namespace std;

int n, m;		  // n: 쉼터의 수, m: 길의 수
int height[5001]; // height[i]: i번째 쉼터의 높이
int dp[5001];	  // dp[i] = i번째 쉼터에서 출발했을 때 최대로 방문하는 쉼터의 개수
vector<vector<int>> v; // 간선의 정보를 저장하는 인접 리스트

int go(int node)
{
	if (dp[node]) // 만약 계산된 쉼터이면
	{
		return dp[node];
	}

	int ret = 0;

	for (auto &i : v[node])
	{
		if (height[i] > height[node]) // 방문하지 않은 쉼터이면서 높이가 높은 쉼터를 방문
		{
			ret = max(ret, go(i)); // 최댓값으로 갱신
		}
	}

	return dp[node] = ret + 1; // 자기 자신 쉼터 + 1
}

int main()
{
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> height[i];
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << go(i) << '\n';
	}
}