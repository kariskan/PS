#include <iostream>
using namespace std;

int n, happy[1000001], fatigue[1000001];
int happyMin[1000001], happyMax[1000001];	  // 1~i까지 최소 행복, i~n까지 최대 행복
int fatigueMin[1000001], fatigueMax[1000001]; // 1~i까지 최대 피로, i~n까지 최소 피로

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> happy[i] >> fatigue[i];
	}

	int ma = 1000000001, mi = -1;
	for (int i = 1; i <= n; i++)
	{
		if (happy[i] && happy[i] < ma)
		{
			ma = happy[i];
		}
		if (fatigue[i] && fatigue[i] > mi)
		{
			mi = fatigue[i];
		}
		happyMin[i] = ma;
		fatigueMax[i] = mi;
	}

	ma = 1000000001, mi = -1;
	for (int i = n; i >= 1; i--)
	{
		if (happy[i] && happy[i] > mi)
		{
			mi = happy[i];
		}
		if (fatigue[i] && fatigue[i] < ma)
		{
			ma = fatigue[i];
		}
		happyMax[i] = mi;
		fatigueMin[i] = ma;
	}

	int ans = -1;
	for (int i = 1; i < n; i++)
	{
		if (happyMin[i] > happyMax[i + 1] && fatigueMax[i] < fatigueMin[i + 1])
		{
			ans = i;
		}
	}
	cout << ans;
}