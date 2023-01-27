#include <iostream>
using namespace std;

int n, m;							// n: 행의 개수, m: 열의 개수
int a[1025][1025], sum[1025][1025]; // a: 입력 배열, sum: 부분 합 배열

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
		}
	}

	int k; // 질의 개수
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2; // 시작 좌표, 끝 좌표
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << '\n';
	}
}