#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct p {
	int start;
	int end;
	int box;
};
vector<p> v;
int can[2001];
bool compare(p& p1, p& p2) {
	if (p1.end == p2.end) {
		if (p1.start == p2.start) {
			return p1.box < p2.box;
		}
		return p1.start < p2.start;
	}
	return p1.end < p2.end;
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	sort(v.begin(), v.end(), compare);
	int ans = 0, weight = 0;
	for (int i = 0; i < k; i++) {
		int boxWeight = 0;
		for (int j = v[i].start; j < v[i].end; j++) {
			boxWeight = max(boxWeight, can[j]);
		}
		int leftSpace = min(v[i].box, m - boxWeight);
		ans += leftSpace;

		for (int j = v[i].start; j < v[i].end; j++) {
			can[j] += leftSpace;
		}
	}
	cout << ans;
}