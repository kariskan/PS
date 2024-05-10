#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

int n;
vector<int> v1, v2;
int a[4000][4];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v1.push_back(a[i][0] + a[j][1]);
			v2.push_back(a[i][2] + a[j][3]);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	long long answer = 0;

	for (int i = 0; i < v1.size(); i++) {
		int a = upper_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		int b = lower_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		answer += a - b;
	}

	cout << answer;
}