#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int v[1000][1000];
map<int, int> m;
int r, c, k;
int row = 3, col = 3;
bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}
void R() {
	int maxCol = 0;
	for (int i = 0; i < row; i++) {
		int tempRow[100] = { 0, };
		for (int j = 0; j < col; j++) {
			if(v[i][j])	m[v[i][j]]++;
		}
		vector<pair<int, int>> temp;
		for (const auto& k : m) {
			temp.push_back({ k.first, k.second });
		}
		sort(temp.begin(), temp.end(), compare);
		for (int k = 0; k < temp.size(); k++) {
			if (k * 2 >= 100)continue;
			tempRow[k * 2] = (temp[k].first);
			tempRow[k * 2 + 1] = (temp[k].second);
			maxCol = max(maxCol, (k + 1) * 2);
		}
		for (int j = 0; j < max(col, maxCol); j++) {
			v[i][j] = tempRow[j];
		}
		m.clear();
	}
	col = maxCol;
}
void C() {
	int maxRow = 0;
	for (int j = 0; j < col; j++) {
		int tempCol[100] = { 0, };
		for (int i = 0; i < row; i++) {
			if(v[i][j])	m[v[i][j]]++;
		}
		vector<pair<int, int>> temp;
		for (const auto& k : m) {
			temp.push_back({ k.first, k.second });
		}
		sort(temp.begin(), temp.end(), compare);
		for (int k = 0; k < temp.size(); k++) {
			if (k * 2 >= 100)continue;
			tempCol[k * 2] = (temp[k].first);
			tempCol[k * 2 + 1] = (temp[k].second);
			maxRow = max(maxRow, (k + 1) * 2);
		}
		for (int k = 0; k < max(row, maxRow); k++) {
			v[k][j] = tempCol[k];
		}
		m.clear();
	}
	row = maxRow;
}
int main() {
	cin >> r >> c >> k;
	r--;
	c--;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
		}
	}
	if (v[r][c] == k) {
		cout << 0;
		return 0;
	}
	for (int t = 1; t <= 100; t++) {
		if (row >= col) {
			R();
		}
		else {
			C();
		}
		if (v[r][c] == k) {
			cout << t;
			return 0;
		}
	}
	cout << -1;
}