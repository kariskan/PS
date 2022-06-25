#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[50];
vector<int> v[50];
int dp[50];

int go(int n) {
	int ret = 0;
	vector<int> temp;
	int cnt = v[n].size() - 1;
	for (int i = 0; i < v[n].size(); i++) {
		temp.push_back(go(v[n][i]));
	}
	sort(temp.begin(), temp.end());
	for (int i = 0; i < temp.size(); i++) {
		ret = max(ret, temp[i] + cnt);
		cnt--;
	}
	return ret + 1;
}
bool compare(int a, int b) {
	return a > b;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		v[map[i]].push_back(i);
	}
	cout << go(0) - 1;
	return 0;
}