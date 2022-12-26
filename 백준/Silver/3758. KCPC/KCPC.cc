#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

bool compare(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2)
{
	if (p1.first == p2.first)
	{
		if (p1.second.first == p2.second.first)
		{
			return p1.second.second < p2.second.second;
		}
		return p1.second.first < p2.second.first;
	}
	return p1.first > p2.first;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		pair<int, pair<int, int>> info[101]; // 최종 점수, 제출 횟수, 제출 시간
		int scoreInfo[101][101] = {
			0,
		};
		int n, k, t, m;
		cin >> n >> k >> t >> m;
		for (int i = 1; i <= m; i++)
		{
			int teamid, pnum, score;
			cin >> teamid >> pnum >> score;
			info[teamid].second.first++;
			info[teamid].second.second = i;
			if (scoreInfo[teamid][pnum] == 0)
			{
				info[teamid].first += score;
				scoreInfo[teamid][pnum] = score;
			}
			else
			{
				if (scoreInfo[teamid][pnum] > score)
				{
					continue;
				}
				info[teamid].first = info[teamid].first - scoreInfo[teamid][pnum] + score;
				scoreInfo[teamid][pnum] = score;
			}
		}
		int myScore = info[t].first, mySubmit = info[t].second.first, mySubmitTime = info[t].second.second;
		sort(info + 1, info + 1 + n, compare);
		for (int i = 1; i <= n; i++)
		{
			if (myScore == info[i].first && mySubmit == info[i].second.first && mySubmitTime == info[i].second.second)
			{
				cout << i << '\n';
				break;
			}
		}
	}
}