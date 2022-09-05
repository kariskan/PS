#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;

vector<string> v;

void go(string res, int idx, string ok) {

	if (idx == s.length()) {
		v.push_back(res);
		return;
	}

	if (s[idx] == '(') {
		go(res + "(", idx + 1, ok + "1");
		go(res, idx + 1, ok + "0");
	}
	else if (s[idx] == ')') {
		if (ok.back() == '1') {
			ok.pop_back();
			go(res + ")", idx + 1, ok);
		}
		else {
			ok.pop_back();
			go(res, idx + 1, ok);
		}
	}
	else {
		go(res + s[idx], idx + 1, ok);
	}
}

int main() {
	cin >> s;

	go("", 0, "");

	v.erase(v.begin());

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto& i : v) {
		cout << i << '\n';
	}
}