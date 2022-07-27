#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int len[21][300000];
vector<int> seq[21];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		len[s.length()][i] = 1;
	}
	for (int i = 1; i <= 20; i++) {
		for (int j = 0; j < n; j++) {
			if (len[i][j])seq[i].push_back(j);
			len[i][j] += len[i][j - 1];
		}
	}
	long long ans = 0;
	for (int i = 1; i <= 20; i++) {
		for (int j = 0; j < seq[i].size(); j++) {
			ans += len[i][min(seq[i][j] + m, n - 1)] - len[i][seq[i][j]];
		}
	}
	cout << ans;
}