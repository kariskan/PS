#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<int, int> m;
map<int, int> order;
vector<pair<int, pair<int, int>>> v; //num, 횟수, 순서
bool compare(pair<int, pair<int, int>>& p1, pair<int, pair<int, int>>& p2) {
	if (p1.second.first == p2.second.first) {
		return p1.second.second < p2.second.second;
	}
	return p1.second.first > p2.second.first;
}
int main() {
	int n, c; cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		m[num]++;
		if (order.find(num) == order.end()) {
			order[num] = i;
		}
	}
	for (auto& i : m) {
		v.push_back({ i.first, {i.second, order[i.first]} });
	}
	sort(v.begin(), v.end(), compare);
	for (auto& i : v) {
		for (int j = 0; j < i.second.first; j++) {
			cout << i.first << ' ';
		}
	}
}