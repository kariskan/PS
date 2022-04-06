#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

int h[90000];
vector<pair<int, int>> st;
vector<pair<int, int>>v;
vector<int> ve;

bool containRange(pair<int, int> first, pair<int, int> second) {
	if (second.first >= first.first && second.first <= first.second)return true;
	if (second.second >= first.first && second.second <= first.second)return true;
	if (first.first >= second.first && first.first <= second.second)return true;
	if (first.second >= second.first && first.second <= second.second)return true;
	return false;
}

int solution(vector<string> lines) {
	int answer = 0;
	for (string s : lines) {
		istringstream ss(s);
		string stringBuffer;
		vector<string> x;
		while (getline(ss, stringBuffer, ' ')) {
			x.push_back(stringBuffer);
		}
		int start = stoi(x[1].substr(0, 2)) * 3600000
			+ stoi(x[1].substr(3, 2)) * 60000
			+ stoi(x[1].substr(6, 2)) * 1000
			+ stoi(x[1].substr(9, 3))
			- stoi(x[2].substr(0, 1)) * 1000 + 1;
		if (x[2].length() > 2)
			start -= stoi(x[2].substr(2, x[2].length() - 3))
			* (int)pow(10, 6 - x[2].length());
		int end = stoi(x[1].substr(0, 2)) * 3600000
			+ stoi(x[1].substr(3, 2)) * 60000
			+ stoi(x[1].substr(6, 2)) * 1000
			+ stoi(x[1].substr(9, 3));

		v.push_back({ start,end });
		ve.push_back(start);
		ve.push_back(end);
	}
	sort(ve.begin(), ve.end());
	for (int k : ve) {
		int start = k;
		int end = start + 999;
		int t = 0;
		for (const pair<int, int> p : v) {
			if (containRange({ start,end }, p)) {
				t++;
			}
		}
		answer = max(answer, t);
	}
	return answer;
}