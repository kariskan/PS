#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		v.push_back(s[i] - 'a');
	}
	sort(v.begin(), v.end());
	int ans = 0;
	do
	{
		int ok = 1;
		for (int i = 0; i < s.length() - 1; i++)
		{
			if (v[i] == v[i + 1])
			{
				ok = 0;
				break;
			}
		}
		if (ok)
		{
			ans++;
		}
	} while (next_permutation(v.begin(), v.end()));
	
	cout << ans;
}