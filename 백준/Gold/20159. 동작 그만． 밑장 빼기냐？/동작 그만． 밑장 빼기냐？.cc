#include <iostream>
using namespace std;

int n, a[100001], odd[100001], even[100001]; // a: 입력, odd: 홀수 인덱스 누적합, even: 짝수 인덱스 누적합

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i % 2 == 1)
		{
			odd[i] = a[i] + odd[i - 1];
			even[i] = even[i - 1];
		}
		else
		{
			even[i] = a[i] + even[i - 2];
			odd[i] = odd[i - 1];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) // i번째에서 카드를 밑장 뺐을 때
	{
		if (i % 2 == 0)
		{
			ans = max(ans, odd[i] + even[n - 1] - even[i - 1]); // 짝수에서 밑장 뺏을 경우, 이때까지 홀수 전부 + 맨 마지막 빼고 짝수 더하기
		}
		else
		{
			ans = max(ans, odd[i - 1] + even[n] - even[i]); // 홀수에서 밑장 뺏을 경우, 이떄 - 1까지 홀수 전부 + 맨마지막 + 이후 짝수 전부;
		}
	}
	ans = max(ans, odd[n]);
	cout << ans;
}