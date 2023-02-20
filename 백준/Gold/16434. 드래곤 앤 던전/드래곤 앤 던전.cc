#include <iostream>
#include <climits>
using namespace std;

int n, a;

struct element
{
	int type;
	int atk;
	int hp;
};

element e[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a;
	for (int i = 1; i <= n; i++)
	{
		cin >> e[i].type >> e[i].atk >> e[i].hp;
	}

	long long left = 0, right = LLONG_MAX;
	long long ans = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long nowHP = mid, nowATK = a;
		int ok = 1;

		for (int i = 1; i <= n; i++)
		{
			if (e[i].type == 1)
			{
				long long div = (e[i].hp + nowATK - 1) / nowATK - 1;
				nowHP -= e[i].atk * div;
			}
			else
			{
				nowHP = min(mid, nowHP + e[i].hp);
				nowATK += e[i].atk;
			}

			if (nowHP <= 0)
			{
				ok = 0;
				break;
			}
		}

		if (ok)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << ans;
}