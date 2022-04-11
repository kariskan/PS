#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int maxTime;
vector<int> table;
int personCnt[1440];

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	maxTime = 9 + ((n - 1) * t) / 60 + ((n - 1) * t) % 60;

	sort(timetable.begin(), timetable.end());

	for (string s : timetable) {
		stringstream ss(s);
		vector<string> t;
		string temp;
		while (getline(ss, temp, ':')) {
			t.push_back(temp);
		}
		int hour = stoi(t[0]);
		int minute = stoi(t[1]);
		table.push_back(hour * 60 + minute);
	}
	int idx = 0;
	int time = 540;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int full = m;
		for (int j = idx; j < table.size(); j++) {
			if (table[j] <= time) {
				idx++;
				full--;
				if (!full)break;
			}
		}

		if (i + 1 == n) {
			if (!full) {
				res = table[idx - 1] - 1;
			}
			else {
				res = time;
			}
		}
		time += t;
		if (time >= 1440)break;
	}

	int hour = res / 60;
	if (hour < 10)answer += "0";
	answer += to_string(hour) + ":";
	if (res % 60 < 10)answer += "0";
	answer += to_string(res % 60);
	return answer;
}