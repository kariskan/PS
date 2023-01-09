#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a, b;
vector<int> v;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		a.push_back(k);
	}
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		b.push_back(k);
		for (int j = 0; j < n; j++)
		{
			v.push_back(a[j] * b[i]);
		}
	}
	sort(v.begin(), v.end());
	while (m--)
	{
		for (int i = 0; i < n; i++)
		{
			int ok = 0;
			for (int j = 0; j < b.size(); j++)
			{
				if (b[j] * a[i] == v[v.size() - 1])
				{
					b.erase(b.begin() + j);
					ok = 1;
					break;
				}
			}
			if (ok)
			{
				break;
			}
		}
		v.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < b.size(); j++)
			{
				v.push_back(a[i] * b[j]);
			}
		}
		sort(v.begin(),v.end());
	}
	cout << v[v.size() - 1];
}