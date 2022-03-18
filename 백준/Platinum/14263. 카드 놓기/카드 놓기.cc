#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char ItoC[100];
int CtoI[130];
int ind[130];
int n, m;
string s[50];
int k = 0;
bool map[100][100] = { false, };
string run() {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (map[i][j]) {
				ind[j]++;
			}
		}
	}
	string ans = "";
	priority_queue<char, vector<char>, greater<char>>pq;
	for (int i = 0; i < k; i++) {
		if (!ind[i]) {
			pq.push(ItoC[i]);
		}
	}
	while (!pq.empty()) {
		char a = pq.top(); pq.pop();
		ans += a;
		int b = CtoI[a];
		for (int i = 0; i < k; i++) {
			if (map[b][i]) {
				ind[i]--;
				if (!ind[i]) {
					pq.push(ItoC[i]);
				}
			}
		}
	}
	if (ans.length() != k)return "-1";
	else return ans;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < 130; i++) {
		CtoI[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] != '.') {
				char c = s[i][j];
				if (CtoI[c] == -1) {
					CtoI[c] = k;
					ItoC[k] = c;
					k++;
				}
			}
		}
	}
	for (int i = 0; i < k; i++) {
		int top = n - 1;
		int left= m - 1;
		int right = 0;
		int bottom = 0;
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < m; l++) {
				if (s[j][l] == ItoC[i]) {
					top = min(top, j);
					left = min(left, l);
					right = max(right, l);
					bottom = max(bottom, j);
				}
			}
		}
		for (int j = top; j <= bottom; j++) {
			for (int l = left; l <= right; l++) {
				if (s[j][l] == '.') {
					cout << -1;
					return 0;
				}
				if (s[j][l] != ItoC[i]) {
					map[i][CtoI[s[j][l]]] = true;
				}
			}
		}
	}
	string ans = run();
	cout << ans;
}