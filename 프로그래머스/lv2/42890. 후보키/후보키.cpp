#include <string>
#include <vector>
#include <map>
using namespace std;
vector<vector<string>> relation;
int visit[8];
int len, tlen;
vector<vector<int>> t;
bool check(vector<int> tuple) {
	map<vector<string>, int> ma;
	for (int i = 0; i < len; i++) {
		int rLen = tuple.size();
		vector<string> temp;
		for (int j = 0; j < rLen; j++) {
			temp.push_back(relation[i][tuple[j]]);
		}
		if (ma.find(temp) != ma.end()) {
			return false;
		}
		ma[temp]++;
	}
	return true;
}
bool minimum(vector<int> tuple) {
	if (tuple.size() == 1 || t.empty())return true;

	for (const vector<int>& v : t) {
		bool flag = false;
		for (const int& num : v) {
			bool find = false;
			for (const int& k : tuple) {
				if (num == k) {
					find = true;
				}
			}
			if (!find) {
				flag = true;
				break;
			}
		}
		if (!flag)return false;
	}
	return true;
}
void dfs(int idx, vector<int> tuple, int cnt) {
	if (tuple.size() > cnt)return;
	if (cnt == tuple.size() && check(tuple) && minimum(tuple)) {
		t.push_back(tuple);
		return;
	}
	for (int i = idx + 1; i < tlen; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			tuple.push_back(i);
			dfs(i, tuple, cnt);
			tuple.pop_back();
			visit[i] = 0;
		}
	}
}
int solution(vector<vector<string>> relation) {
	::relation = relation;
	len = relation.size();
	tlen = relation[0].size();
	for(int i=1;i<=tlen;i++) dfs(-1, {}, i);
	return t.size();
}