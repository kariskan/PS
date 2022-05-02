#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<int>> map;
int m[200000];
int relation[200000];
int visit[200000];
void findParent(int v) {
	if (visit[v])return;
	if (!visit[m[v]]) {
		relation[m[v]] = v;
		return;
	}
	visit[v] = 1;
	/*
	*	먼저 방문해야 하는 노드를 탐색하고 (relation[v])
	*	이어진 노드 탐색 (u)
	*/
	if(!visit[relation[v]]) findParent(relation[v]);
	for (int u : map[v]) if(!visit[u]) findParent(u);
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	map.resize(n);
	for (const vector<int>& v : path) {
		map[v[0]].push_back(v[1]);
		map[v[1]].push_back(v[0]);
	}
	for (const vector<int>& v : order) {
		m[v[1]] = v[0];
	}
	if (m[0])return false;
	visit[0] = 1;
	for (int v : map[0])findParent(v);

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			return false;
		}
	}

	return true;
}