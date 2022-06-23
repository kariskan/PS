#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> v, vIn;
int inp[200001];
int sInp[200001];
int in[200001];
int color[200001];
int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int c, si;
		cin >> c >> si;
		v[c].push_back(si);
		color[i] = c;
		inp[i] = in[i] = si;
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	vIn = v;
	sort(inp, inp + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < v[i].size(); j++) {
			v[i][j] += v[i][j - 1];
		}
		sInp[i] += sInp[i - 1] + inp[i];
	}

	for (int i = 1; i <= n; i++) {
		int standard = in[i];
		int start = 1;
		int end = n;
		int mid = (start + end) / 2;
		int t = 0;
		while (start <= end) {
			mid = (start + end) / 2;

			if (inp[mid] < standard && t < sInp[mid]) {
				t = sInp[mid];
			}

			if (standard <= inp[mid]) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}

		start = 0;
		int idx = color[i];
		end = v[idx].size() - 1;
		mid = (start + end) / 2;
		int t2 = 0;
		while (start <= end) {
			mid = (start + end) / 2;

			if (vIn[idx][mid] < standard && t2 < v[idx][mid]) {
				t2 = v[idx][mid];
			}

			if (standard <= vIn[idx][mid]) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		cout << t - t2 << "\n";
	}

	return 0;
}