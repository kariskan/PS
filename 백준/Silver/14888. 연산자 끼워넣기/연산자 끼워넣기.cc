#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> inp;
vector<int> op;
int minAns = 1000000001;
int maxAns = -1000000001;
void dfs(int plus, int minus, int multiple, int divide, int count, int ans) {
	if (count == n) {
		minAns = min(minAns, ans);
		maxAns = max(maxAns, ans);
		return;
	}
	if (plus > 0)
		dfs(plus - 1, minus, multiple, divide, count + 1, ans + inp[count]);
	if (minus > 0)
		dfs(plus, minus - 1, multiple, divide, count + 1, ans - inp[count]);
	if (multiple > 0)
		dfs(plus, minus, multiple - 1, divide, count + 1, ans * inp[count]);
	if (divide > 0)
		dfs(plus, minus, multiple, divide - 1, count + 1, ans / inp[count]);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		inp.push_back(a);
	}
	for (int i = 0; i < 4; i++) {
		int a; cin >> a;
		op.push_back(a);
	}
	dfs(op[0], op[1], op[2], op[3], 1, inp[0]);
	cout << maxAns << "\n" << minAns;
}