#include <string>
#include <vector>
#include <deque>
using namespace std;
vector<string> d;
int find(string s) {
	for (int i = 0; i < d.size(); i++) {
		if (d[i] == s)return i;
	}
	return -1;
}
string toLower(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;
		}
	}
	return s;
}
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	for (string s : cities) {
		int idx = find(toLower(s));
		if (idx == -1) {
			answer += 5;
			if (!cacheSize)continue;
			if (d.size() == cacheSize)d.erase(d.begin());
			d.push_back(toLower(s));
		}
		else {
			answer++;
			d.erase(d.begin() + idx);
			d.push_back(toLower(s));
		}
	}
	return answer;
}