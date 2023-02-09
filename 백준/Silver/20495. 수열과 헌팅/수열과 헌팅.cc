#include <iostream>
#include <algorithm>
using namespace std;

int l[500000], r[500000];
pair<int, int> p[500000];

int main()
{
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		p[i] = {a - b, a + b};
		l[i] = a - b;
		r[i] = a + b;
	}
	
	sort(l, l + n);
	sort(r, r + n);

	for (int i = 0; i < n; i++)
	{
		int left = 0, right = n - 1;
		int la = 0, ra = 0;
		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (r[mid] >= p[i].first)
			{
				right = mid - 1;
				la = mid;
			}
			else
			{
				left = mid + 1;
			}
		}

		left = 0, right = n - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (l[mid] <= p[i].second)
			{
				left = mid + 1;
				ra = mid;
			}
			else
			{
				right = mid - 1;
			}
		}

		cout << la + 1 << ' ' << ra + 1 << '\n';
	}	
}