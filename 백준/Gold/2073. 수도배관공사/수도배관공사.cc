#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int d, p;				 // d = 총 수도관이 길이, p = 구매한 파이프의 개수
pair<int, int> inp[351]; // inp[i] = {i번째 파이프의 길이, i번째 파이프의 용량}
int dp[100001];			 // dp[j] = 파이프로 j길이를 만들었을 때 최대 용량

void Input()
{
	cin >> d >> p;
	for (int i = 1; i <= p; i++)
	{
		cin >> inp[i].first >> inp[i].second;
	}
	sort(inp + 1, inp + p + 1);
}

void Solve()
{
	dp[0] = INT_MAX;
	for (int i = 1; i <= p; i++)
	{
		for (int j = d; j >= inp[i].first; j--)
		{
			//[j - 현재 길이]의 용량과, 현재 파이프의 용량중 작은 것이 용량
			dp[j] = max(dp[j], min(dp[j - inp[i].first], inp[i].second));
		}
	}

	cout << dp[d];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solve();
}
