#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	long long ans = 0;
	v.erase(unique(v.begin(), v.end()), v.end());
	while (v.size() != 1)
	{

		int minElement = *min_element(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] != minElement)
			{
				continue;
			}
			int left = i - 1, right = i + 1;

			while (left >= 0 && v[left] == minElement)
			{
				left--;
			}
			while (right < v.size() && v[right] == minElement)
			{
				right++;
			}
			int smaller = 1000000000;
			if (left >= 0)
			{
				smaller = v[left];
			}
			if (right < v.size())
			{
				smaller = min(smaller, v[right]);
			}

			ans += smaller - minElement;
			v[i] = smaller;
			v.erase(unique(v.begin(), v.end()), v.end());
		}
	}
	
	cout << ans;
}