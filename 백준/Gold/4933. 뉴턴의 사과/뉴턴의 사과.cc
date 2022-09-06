#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int parent[2][30];

int go(int i, int idx,  vector<string>& inp, int pre) {
	if (idx >= inp.size()) return 0;
	if (inp[idx] == "nil") return 1;

	parent[i][inp[idx][0] - 'A' + 1] = pre;

	int sub = go(i, idx + 1, inp, inp[idx][0] - 'A' + 1);
	sub += go(i, sub + idx + 1, inp, inp[idx][0] - 'A' + 1);

	return sub + 1;
}

int main() {
	int n; cin >> n;

	while (n--) {

		string s;
		vector<string> inp1, inp2;
		memset(parent, 0, sizeof(parent));

		while (1) {
			cin >> s;
			if (s == "end")break;
			inp1.push_back(s);
		}
		reverse(inp1.begin(), inp1.end());

		while (1) {
			cin >> s;
			if (s == "end")break;
			inp2.push_back(s);
		}
		reverse(inp2.begin(), inp2.end());

		go(0, 0, inp1, -1);
		go(1, 0, inp2, -1);

		bool ok = true;

		for (int i = 1; i < 27; i++) {
			if (parent[0][i] != parent[1][i]) {
				ok = false;
				break;
			}
		}

		if (ok)cout << "true\n";
		else cout << "false\n";
	}
}