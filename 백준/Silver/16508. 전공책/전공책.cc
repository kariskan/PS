#include <iostream>
using namespace std;

int n, visit[70000];
string s;
pair<int, string> p[16];

int main() {
	cin >> s >> n;

	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}

	int ans = -1;
	
	for (int i = 1; i < (1 << n); i++) {
		int temp[10] = { 0, };
		int price = 0;
		for (int j = 0; j < n; j++) {
			int temp2[50] = { 0, };
			if (i & (1 << j)) {
				price += p[j].first;
				for (int k = 0; k < s.length(); k++) {
					if (temp[k])continue;
					for (int l = 0; l < p[j].second.length(); l++) {
						if (s[k] == p[j].second[l] && !temp2[l]) {
							temp[k] = 1;
							temp2[l] = 1;
							break;
						}
					}
				}
			}
		}

		int ok = 1;
		for (int l = 0; l < s.length(); l++) {
			if (!temp[l])ok = 0;
		}
		if (ok) {
			if (ans == -1 || ans > price)ans = price;
		}
	}

	cout << ans;
}