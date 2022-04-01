#include <iostream>
using namespace std;
int map[1000][1000];
long long col[1000], row[1000];
long long sum[1000][1000];
long long ans;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if ((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1))sum[i][j] = map[i][j];
			else if (i == 0 || i == n - 1 || j == 0 || j == m - 1)sum[i][j] = map[i][j] * 2;
			else sum[i][j] = map[i][j] * 4;
			ans += sum[i][j];
		}
	}
	long long rowMax = -10000000000, colMax = -10000000000, rowMin = 10000000000, colMin = 10000000000;
	int rowMaxIdx = -1, colMaxIdx = -1, rowMinIdx = -1, colMinIdx = -1;
	for (int i = 0; i < n; i++) {
		long long colSum = 0;
		for (int j = 0; j < m; j++) {
			colSum += sum[i][j];
		}
		col[i] = colSum;
		if (i == 0 || i == n - 1) {
			if (col[i] > colMax) {
				colMax = col[i];
				colMaxIdx = i;
			}
		}
		else {
			if (col[i] < colMin) {
				colMin = col[i];
				colMinIdx = i;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		long long rowSum = 0;
		for (int j = 0; j < n; j++) {
			rowSum += sum[j][i];
		}
		row[i] = rowSum;
		if (i == 0 || i == m - 1) {
			if (row[i] > rowMax) {
				rowMax = row[i];
				rowMaxIdx = i;
			}
		}
		else {
			if (row[i] < rowMin) {
				rowMin = row[i];
				rowMinIdx = i;
			}
		}
	}
	long long sumMax = -1000000000;
	if (rowMinIdx != -1)
		if (sumMax < row[rowMaxIdx] - row[rowMinIdx] / 2) {
			sumMax = row[rowMaxIdx] - row[rowMinIdx] / 2;
		}
	if (colMinIdx != -1)
		if (sumMax < col[colMaxIdx] - col[colMinIdx] / 2) {
			sumMax = col[colMaxIdx] - col[colMinIdx] / 2;
		}
	cout << max(ans, ans + sumMax);
}