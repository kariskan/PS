// #include <iostream>
// #include <cstring>
// #include <vector>
// using namespace std;

// int a[40001], dp[50][40001]; // dp[i][j]: i번째까지 동전으로 j원을 만드는 방법의 수
// vector<int> prime;			 // 소수들을 저장하는 리스트

// int main()
// {
// 	int n;
// 	cin >> n;
// 	prime.push_back(0);

// 	// 에라토스 테네스
// 	for (int i = 2; i * i <= 40000; i++)
// 	{
// 		if (!a[i])
// 		{
// 			prime.push_back(i);
// 			for (int j = i * i; j <= 40000; j += i)
// 			{
// 				a[j] = 1;
// 			}
// 		}
// 	}

// 	int mod = 123456789;
// 	for (int i = 1; i < prime.size(); i++)
// 	{
// 		dp[i][0] = 1;
// 		for (int j = 1; j <= n; j++)
// 		{
// 			dp[i][j] = dp[i - 1][j];
// 			if (j >= prime[i])
// 			{
// 				dp[i][j] = (dp[i][j] % mod + dp[i][j - prime[i]] % mod) % mod;
// 			}
// 		}
// 	}

// 	cout << dp[prime.size() - 1][n];
// }

#include <iostream>
using namespace std;

int a[1001];
int dp[1001]; // dp[i] = i번째 학생까지 그룹으로 묶었을 때 잘 짜여진 정도의 최댓값
int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i] = max(dp[i], dp[j] + abs(a[i] - a[j + 1]));
		}
	}

	cout << dp[n];
}