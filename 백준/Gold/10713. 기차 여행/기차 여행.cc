#include <iostream>
#include <vector>
#include <map>
using namespace std;

// A: 티켓 가격, B: IC 카드 이동 비용, C: IC 구입 비용, n: 역 개수
int A[100001], B[100001], C[100001], n, m;
vector<int> inp;	// 경로
int course[100001]; // course[i]: i와 i+1을 잇는 철도를 사용하는 횟수

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int p;
		cin >> p;
		inp.push_back(p);
		if (i > 0)
		{
			int mi = min(inp[i - 1], inp[i]);
			int ma = max(inp[i - 1], inp[i]);
			for (int j = mi; j < ma; j++)
			{
				course[j]++;
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		cin >> A[i] >> B[i] >> C[i];
	}
	long long ans = 0;
	for (int i = 1; i < n; i++)
	{
		ans += min(A[i] * course[i], B[i] * course[i] + C[i]);
	}

	cout << ans;
}