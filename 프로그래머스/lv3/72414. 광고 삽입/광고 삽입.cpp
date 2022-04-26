#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

long long convert(string s) {
	return stoll(s.substr(0, 2)) * 3600 + stoll(s.substr(3, 2)) * 60 + stoll(s.substr(6, 2));
}

string reConvert(long long answerTime) {
	string res = "";
	long long hour = answerTime / 3600;
	if (hour < 10)res.append("0" + to_string(hour) + ":");
	else res.append(to_string(hour) + ":");
	long long minute = (answerTime - hour * 3600) / 60;
	if (minute < 10)res.append("0" + to_string(minute) + ":");
	else res.append(to_string(minute) + ":");
	long long second = answerTime % 60;
	if (second < 10) res.append("0" + to_string(second));
	else res.append(to_string(second));
	return res;
}

long long timeline[360001];

string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";
	long long total = 0, answerTime = 0, play, adv;
	play = convert(play_time);
	adv = convert(adv_time);

	for (int i = 0; i < logs.size(); i++) {
		long long start = convert(logs[i].substr(0, 8));
		long long end = convert(logs[i].substr(9));
		for (long long j = start; j < end; j++) {
			timeline[j]++;
		}
	}
	
	for (long long i = 0; i < adv; i++) {
		total += timeline[i];
	}

	long long start = 0, end = adv - 1, temp = total;
	
	while (start < play - adv) {
		end++;
		temp = temp - timeline[start] + timeline[end];
		start++;
		
		if (temp > total) {
			answerTime = start;
			total = temp;
		}
	}

	return reConvert(answerTime);
}