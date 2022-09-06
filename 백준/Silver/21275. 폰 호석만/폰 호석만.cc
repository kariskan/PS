#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long get(string s, int k) {
	long long ret = 0;
	long long c = 1;
	while (!s.empty()) {
		if (s.back() <= '9')ret += c * (s.back() - '0');
		else {
			ret += c * (s.back() - 'a' + 10);
		}
		c *= k;
		s.pop_back();
	}
	return ret;
}

int main() {
	string s1, s2;

	cin >> s1 >> s2;

	char k1 = *max_element(s1.begin(), s1.end());
	char k2 = *max_element(s2.begin(), s2.end());

	if (k1 <= '9') {
		k1 = k1 - '0';
	}
	else {
		k1 = k1 - 'a' + 11;
	}

	if (k2 <= '9') {
		k2 = k2 - '0';
	}
	else {
		k2 = k2 - 'a' + 11;
	}

	vector<pair<long long, pair<int, int>>> ans;

	for (int i = k1; i <= 36; i++) {
		for (int j = k2; j <= 36; j++) {
			if (i == j)continue;
			if (get(s1, i) == get(s2, j)) {
				ans.push_back({ get(s1,i),{i,j} });
			}
		}
	}

	if (ans.empty()) cout << "Impossible";
	else if (ans.size() == 1) {
		cout << ans[0].first << ' ' << ans[0].second.first << ' ' << ans[0].second.second;
	}
	else cout << "Multiple";
}