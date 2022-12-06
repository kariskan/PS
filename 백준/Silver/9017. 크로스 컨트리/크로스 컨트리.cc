#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		map<int, priority_queue<int, vector<int>, greater<int>>> ma;
		map<int, int> counter;
		vector<int> inp;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			counter[num]++;
			inp.push_back(num);
		}
		int depose = 0;
		for (int i = 0; i < n; i++)
		{
			if (counter[inp[i]] == 6)
			{
				ma[inp[i]].push(i - depose);
			}
			else
			{
				depose++;
			}
		}
		int idx, maxAns = 1000000000, fifth = 0;
		int j = 0;
		for (auto &i : ma)
		{
			if (i.second.size() != 6)
			{
				continue;
			}
			int score = 0;
			for (int j = 0; j < 4; j++)
			{
				score += i.second.top();
				i.second.pop();
			}
			if (maxAns >= score)
			{
				if (maxAns == score)
				{
					if (fifth > i.second.top())
					{
						idx = i.first;
						fifth = i.second.top();
					}
				}
				else
				{
					idx = i.first;
					fifth = i.second.top();
					maxAns = score;
				}
			}
		}
		cout << idx << '\n';
	}
}