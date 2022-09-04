#include <iostream>
#include <vector>
using namespace std;

int r1, c1, r2, c2;

int getN(int n) {
	int cnt = 0;
	while (n) {
		cnt++;
		n /= 10;
	}
	return cnt;
}

int main() {

	ios_base::sync_with_stdio(0);
	cout.tie(0);

	cin >> r1 >> c1 >> r2 >> c2;

	vector<int> v;
	int maxElement = 0;

	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {

			int r = r1 + i;
			int c = c1 + j;

			int k = max(abs(r), abs(c));
			int start = (k * 2 - 1) * (k * 2 - 1) + 1;
			if (r == -k) {
				v.push_back(start + k * 2 - 1 + (k - c));
			}
			else if (r == k) {
				v.push_back(start + k * 2 - 1 + k * 2 + k * 2 + (c + k));
			}
			else if (c == -k) {
				v.push_back(start + k * 2 - 1 + k * 2 + (r + k));
			}
			else if (c == k) {
				v.push_back(start + (k - r - 1));
			}
			maxElement = max(maxElement, v.back());
		}
	}

	int cnt = getN(maxElement);

	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			int num = getN(v[i * (c2 - c1 + 1) + j]);
			for (int k = 0; k < cnt - num; k++)cout << ' ';
			cout << v[i * (c2 - c1 + 1) + j] << ' ';
		}
		cout << '\n';
	}
}