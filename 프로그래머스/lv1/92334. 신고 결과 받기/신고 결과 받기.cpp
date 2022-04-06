#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

pair<string, string> splitString(string s) {
	int len = s.length();
	string first = "";
	string second = "";
	bool brk = false;
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			brk = true;
			continue;
		}
		if (!brk) {
			first += s[i];
		}
		else {
			second += s[i];
		}
	}
	return { first, second };
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	sort(report.begin(), report.end());
	map<string, int> reportCount;
	vector<int> answer;
	vector<pair<string, string>> reportList;
	pair<string, string> old, latest;

	int reportSize = report.size();
	for (int i = 0; i < reportSize; i++) {
		pair<string, string> latest = splitString(report[i]);
		if (i > 0)
			if(latest.first == old.first && latest.second == old.second) {
			continue;
		}
		reportList.push_back({ latest.first,latest.second });
		if (reportCount.find(latest.second) == reportCount.end()) {
			reportCount.insert({ latest.second, 1 });
		}
		else {
			reportCount[latest.second]++;
		}
		old = latest;
	}

	for (int i = 0; i < id_list.size(); i++) {
		answer.push_back(0);
	}

	int lLen = reportList.size();
	for (int i = 0; i < lLen; i++) {
		if (reportCount[reportList[i].second] >= k) {
			for (int j = 0; j < id_list.size(); j++) {
				if (reportList[i].first == id_list[j]) {
					answer[j]++;
				}
			}
		}
	}
	return answer;
}