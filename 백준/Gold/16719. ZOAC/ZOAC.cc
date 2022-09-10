#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
int visit[100];

void go(string t, int index) {
	if (!t.empty()) {
		cout << t << '\n';
	}
	if (t == s) return;

	int idx = 0;
	string k = t;
	for (int i = 0; i < s.length(); i++) {
		if (visit[i]) continue;
		string l = "";
		for (int j = 0; j < s.length(); j++) {
			if (i == j || visit[j])l.push_back(s[j]);
		}
		if (k.length() < l.length() || k > l) {
			k = l;
			idx = i;
		}
	}

	visit[idx] = 1;

	go(k, idx);
}

int main() {

	ios_base::sync_with_stdio(0);
	cout.tie(0);

	cin >> s;

	go("", -1);
}