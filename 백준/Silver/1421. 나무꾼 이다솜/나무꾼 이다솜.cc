#include <iostream>
using namespace std;

long long n, c, w, maxLen;
long long a[50];

int main()
{
	cin >> n >> c >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		maxLen = max(maxLen, a[i]);
	}
	long long ans = 0;
	for (int i = 1; i <= maxLen; i++)
	{
		long long cut = 0, cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j] < i)
			{
				continue;
			}
			int nowCut, nowCnt;
			if (a[j] % i == 0)
			{
				nowCut = a[j] / i - 1;
			}
			else
			{
				nowCut = a[j] / i;
			}
			nowCnt = a[j] / i;
			if (nowCut * c > nowCnt * w * i)
			{
				continue;
			}
			cnt += nowCnt;
			cut += nowCut;
		}
		ans = max(ans, cnt * i * w - c * cut);
	}

	cout << ans;
}