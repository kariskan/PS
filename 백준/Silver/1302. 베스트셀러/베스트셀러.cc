#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<string, int> ma;
	int n;
	cin >> n;
	int c = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ma[s]++;
		c = max(c, ma[s]);
	}
	for (auto& i : ma) {
		if (i.second == c) {
			cout << i.first;
			break;
		}
	}
}