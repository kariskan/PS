#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> m;
vector<string> order;
vector<int> ans(11);
vector<string> d;
void dfs(string s, int visit[10], int i, int j, int c) {
	if (s.length() == c) {
		m[s]++;
		if (ans[s.length()] < m[s]) {
			ans[s.length()] = m[s];
			d.clear();
			if (m[s] > 1)
				d.push_back(s);
		}
		else if (ans[s.length()] == m[s] && m[s] > 1) {
			d.push_back(s);
		}
		return;
	}
	for (int k = j; k < order[i].length(); k++) {
		if (!visit[k]) {
			visit[k] = 1;
			dfs(s + order[i][k], visit, i, k + 1, c);
			visit[k] = 0;
		}
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {

	order = orders;
	vector<string> answers;
	for (int i = 0; i < order.size(); i++) {
		sort(order[i].begin(), order[i].end());
	}
	for (int k = 0; k < course.size(); k++) {
		m.clear();
		for (int i = 0; i < order.size(); i++) {
			int visit[10] = { 0, };
			for (int j = 0; j < order[i].size(); j++) {
				if (!visit[j]) {
					visit[j] = 1;
					string t = "";
					t.push_back(order[i][j]);
					dfs(t, visit, i, j + 1, course[k]);
					visit[j] = 0;
					t.pop_back();
				}
			}
		}
		for (string k : d) answers.push_back(k);
	}

	sort(answers.begin(), answers.end());
	return answers;
}