#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> m;
vector<int> solution(vector<string> gems) {
	int n = gems.size();
	vector<string> gems2 = gems;
	sort(gems2.begin(), gems2.end());
	gems2.erase(unique(gems2.begin(), gems2.end()), gems2.end());
	int cnt = gems2.size();
	vector<int> answer = { 0,n };
	int left = 0, right = 0;
	while (right < n) {
		m[gems[right]]++;

		while (m[gems[left]] > 1) {
			m[gems[left]]--;
			left++;
		}

		if (m.size() == cnt) {
			if (abs(answer[0] - answer[1]) > abs(left - right)) {
				answer[0] = left + 1;
				answer[1] = right + 1;
			}
		}
		right++;
	}
	return answer;
}
