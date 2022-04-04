#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<string>> t;
vector<vector<string>> ans;
bool visit[10000][2];
int len;
void dfs(string now, vector<string> route, int cnt) {
	if (cnt == len) {
		ans.push_back(route);
	}
	for (int i = 0; i < len; i++) {
		if (now != t[i][0])continue;
		if (!visit[i][1]) {
			visit[i][1] = true;
			route.push_back(t[i][1]);
			dfs(t[i][1], route, cnt + 1);
			visit[i][1] = false;
			route.pop_back();
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	t = tickets;
	len = tickets.size();
	dfs("ICN", { "ICN" }, 0);
	sort(ans.begin(), ans.end());
	return ans[0];
}
