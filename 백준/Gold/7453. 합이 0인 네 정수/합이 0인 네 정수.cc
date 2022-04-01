#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int a[4000], b[4000], c[4000], d[4000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	vector<int> m;
	vector<int> m2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m.push_back(a[i] + b[j]);
			m2.push_back(c[i] + d[j]);
		}
	}
	sort(m.begin(), m.end());
	sort(m2.begin(), m2.end());
	long long ans = 0;
	int mSize = m.size(), m2Size = m2.size();
	int mI = 0, m2I = m2.size() - 1;
	while (mI < m2Size && m2I >= 0) {
		long long firstCnt = 1, secondCnt = 1;
		int firstSum = m[mI], secondSum = m2[m2I];
		if (firstSum + secondSum < 0) {
			mI++;
		}
		else if (firstSum + secondSum > 0) {
			m2I--;
		}
		else {
			while (mI < m2Size - 1 && m[mI] == m[mI + 1]) {
				mI++;
				firstCnt++;
			}
			while (m2I > 0 && m2[m2I] == m2[m2I - 1]) {
				m2I--;
				secondCnt++;
			}
			ans += firstCnt * secondCnt;
			mI++;
			m2I--;
		}
	}
	cout << ans;
}