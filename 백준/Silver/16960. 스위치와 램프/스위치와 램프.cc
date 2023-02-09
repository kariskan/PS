#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
vector<vector<int>> sw;
int c[2001];

int main()
{
	cin >> n >> m;
	sw.resize(n + 1);
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		for (int j = 0; j < c; j++)
		{
			int k;
			cin >> k;
			sw[i + 1].push_back(k);
		}
	}

	for (int i = 1; i <= n; i++) // i번째 스위치를 사용하지 않는다.
	{
		int cnt = 0; // 켜진 램프의 수
		memset(c, 0, sizeof(c));
		for (int j = 1; j <= n; j++)
		{
			// i번째 스위치를 사용하지 않음
			if (i == j)
			{
				continue;
			}
			for (int k = 0; k < sw[j].size(); k++) // j번째 스위치와 연결된 램프를 모두 켠다.
			{
				if (!c[sw[j][k]])
				{
					cnt++;
					c[sw[j][k]] = 1;
				}
			}
		}
		// 모든 램프가 켜졌으면
		if (cnt == m)
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;
}