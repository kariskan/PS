#include <iostream>
#include <vector>
using namespace std;
int a[5][5], visit1[5][5];
vector<int> v;
bool check1() {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		bool ok = true;
		for (int j = 0; j < 5; j++) {
			if (!visit1[i][j]) {
				ok = false;
				break;
			}
		}
		if (ok)cnt++;
	}
	for (int j = 0; j < 5; j++) {
		bool ok = true;
		for (int i = 0; i < 5; i++) {
			if (!visit1[i][j]) {
				ok = false;
				break;
			}
		}
		if (ok)cnt++;
	}
	bool ok = true;
	for (int i = 0; i < 5; i++) {
		if (!visit1[i][i]) {
			ok = false;
			break;
		}
	}
	if (ok)cnt++;
	ok = true;
	for (int i = 0; i < 5; i++) {
		if (!visit1[i][5 - i - 1]) {
			ok = false;
			break;
		}
	}
	if (ok)cnt++;
	return cnt >= 3;
}
int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 25; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < 25; i++) {
		int num = v[i];
		for (int k = 0; k < 5; k++) {
			for (int l = 0; l < 5; l++) {
				if (num == a[k][l])visit1[k][l] = 1;
			}
		}
		if (check1()) {
			cout << i + 1;
			return 0;
		}
	}

}