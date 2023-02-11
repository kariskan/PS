#include <iostream>
using namespace std;

int n, m, l; // m: 자를 수 있는 지점의 수, l: 롤 케이크의 길이
int s[1000]; // 자를 수 있는 길이

int main()
{
	cin >> n >> m >> l;
	for (int i = 0; i < m; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < n; i++)
	{
		int q;
		cin >> q; // 자르는 횟수

		int ans = 0;
		int left = 0, right = 1000000000;

		while (left <= right)
		{
			int mid = (left + right) / 2; // q번 잘랐을 때 최소 롤케이크의 길이

			int previous = 0; // 이전에 자른 롤 케이크의 위치
			int cnt = 0;	  // 자르는 횟수
			for (int j = 0; j < m; j++)
			{
				if (s[j] - previous >= mid)
				{
					cnt++;
					previous = s[j];
				}
			}

			if (l - previous >= mid)
			{
				cnt++;
			}

			if (cnt > q)
			{
				left = mid + 1;
				ans = mid;
			}
			else
			{
				right = mid - 1;
			}
		}

		cout << ans << '\n';
	}
}