#include <iostream>
#include <string>
using namespace std;

int ans, l, r;

// 현재 수가 left와 right 사이에 있는지 확인하는 함수
bool check(string s)
{
	int ss = stoi(s);
	return ss >= l && ss <= r;
}

// 백트래킹
void go(string s)
{
	long long ss = stoll(s);
	// 범위를 넘어갈 경우
	if (ss > r)
	{
		return;
	}
	// 범위에 맞을 경우
	else if (ss >= l && ss <= r)
	{
		if (check(s))
		{
			ans++;
		}
	}

	go(s + "4");
	go(s + "7");
}

int main()
{
	cin >> l >> r;
	go("0");
	
	cout << ans;
}