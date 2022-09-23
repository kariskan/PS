#include <iostream>
#include <string>
using namespace std;

int n;

int go(int a, int b) {
	int cnt = 0;
	string t = to_string(a);
	for (int i = 0; i < t.length(); i++) {
		if ((t[i] - '0') % 2 == 1) {
			cnt++;
		}
	}

	if (t.length() == 1) return cnt;
	else if (t.length() == 2) return cnt + go((t[0] - '0') + (t[1] - '0'), b);
	else {
		int ret = -1;
		for (int i = 1; i < t.length() - 1; i++) {
			for (int j = i + 1; j < t.length(); j++) {
				if (i != j) {
					int t1 = stoi(t.substr(0, i));
					int t2 = stoi(t.substr(i, j - i));
					int t3 = stoi(t.substr(j));
					int k = go(t1 + t2 + t3, b);
					if (b == 0) { //min
						if (ret == -1 || ret > k) ret = k;
					}
					else {
						if (ret == -1 || ret < k) ret = k;
					}
				}
			}
		}
		return cnt + ret;
	}
}

int main() {
	cin >> n;
	cout << go(n, 0) << ' ' << go(n, 1);
}