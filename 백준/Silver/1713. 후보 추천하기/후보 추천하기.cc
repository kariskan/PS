#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

struct info {
	bool valid;
	int studentNum;
	int cnt;
	int time;
};

info a[21];
int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;

		bool flag = false;
		// 이미 게시돼 있는지
		for (int j = 1; j <= n; j++) {
			if (a[j].valid && a[j].studentNum == k) {
				a[j].cnt++;
				flag = true;
			}
		}
		if (!flag) {
			// 빈 자리가 있는지
			for (int j = 1; j <= n; j++) {
				if (!a[j].valid) {
					a[j].valid = true;
					a[j].studentNum = k;
					a[j].cnt = 1;
					a[j].time = i;
					flag = true;
					break;
				}
			}
		}
		if (!flag) {
			int minimumUpCnt = a[1].cnt, oldest = a[1].time;
			int idx = 1;
			for (int j = 2; j <= n; j++) {
				if (a[j].cnt < minimumUpCnt || (a[j].cnt == minimumUpCnt && a[j].time < oldest)) {
					idx = j;
					minimumUpCnt = a[j].cnt;
					oldest = a[j].time;
				}
			}
			a[idx].studentNum = k;
			a[idx].cnt = 1;
			a[idx].time = i;
		}
	}
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (a[i].valid) {
			v.push_back(a[i].studentNum);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}