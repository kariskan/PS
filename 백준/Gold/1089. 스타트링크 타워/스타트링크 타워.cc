#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int n;
vector<string> set = {
	"###...#.###.###.#.#.###.###.###.###.###",
	"#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
	"#.#...#.###.###.###.###.###...#.###.###",
	"#.#...#.#.....#...#...#.#.#...#.#.#...#",
	"###...#.###.###...#.###.###...#.###.###"
};
string s[5];
bool ok(int x, int y) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (set[i][4 * y + j] == '.' && s[i][4 * x + j] == '#') {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < 5; i++) {
		cin >> s[i];
	}
	vector<vector<int>> can(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (ok(i, j)) {
				can[i].push_back(j);
			}
		}
	}
	long long sum = 1;
	for (int i = 0; i < n; i++) {
		sum *= (int)can[i].size();
	}
	if (sum == 0) {
		cout << -1;
		return 0;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long c = 0;
		for (int a : can[i]) {
			c += a;
		}
		ans = ans * 10 + c * (sum / (int)can[i].size());
	}
	cout << fixed << setprecision(10) << ((double)ans / sum);
}