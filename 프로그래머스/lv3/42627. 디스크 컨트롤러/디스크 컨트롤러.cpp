#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//실행시간, 요청시간, 진입시간
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int t = 0;
	int idx = 0;
	int start = -1;
	sort(jobs.begin(), jobs.end());

	while (idx < jobs.size() || !pq.empty()) {
		if (pq.empty()) {
			t = jobs[idx][0] + jobs[idx][1];
			answer += jobs[idx][1];
			idx++;
		}
		else {
			int a = pq.top().first;
			int b = pq.top().second;
			pq.pop();
			t += a;
			answer += t - b;
		}

		while (idx < jobs.size() && jobs[idx][0] <= t) {
			pq.push({ jobs[idx][1], jobs[idx][0] });
			idx++;
		}

	}

	return answer / jobs.size();
}