#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v, v2;
string ans;

int main()
{
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
		cnt += s.length();
	}
	int div = ((m - cnt) / (n - 1)) * (n - 1); // 16
	int nCnt = (m - cnt) - div;				   // 17 - 16

	for (int i = 0; i < n - 1; i++)
	{
		int k = div / (n - 1) + (nCnt ? 1 : 0);
		if (nCnt)
		{
			nCnt--;
		}
		v2.push_back(string(k, '_'));
	}

	sort(v2.begin(), v2.end());
	do
	{
		string temp = v[0];
		for (int i = 0; i < v2.size(); i++)
		{
			temp += v2[i] + v[i + 1];
		}
		if (ans == "" || ans > temp)
		{
			ans = temp;
		}
	} while (next_permutation(v2.begin(), v2.end()));
	cout << ans;
}