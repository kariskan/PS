#include <iostream>
#include <vector>
using namespace std;

bool isCut[100001];
vector<vector<int>> v;
pair<int, int> inp[100001];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	cin >> n;

	v.resize(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> inp[i].first >> inp[i].second;
		v[inp[i].first].push_back(inp[i].second);
		v[inp[i].second].push_back(inp[i].first);
	}

	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() != 1)
		{
			isCut[i] = true;
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == 1)
		{
			if (!isCut[b])
			{
				cout << "no\n";
			}
			else
			{
				cout << "yes\n";
			}
		}
		else
		{
			cout << "yes\n";
		}
	}
}