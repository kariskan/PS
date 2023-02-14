#include <iostream>
#include <vector>
using namespace std;

string s;	   // 입력
vector<int> v; // 밑줄이 있는 인덱스를 저장하는 리스트
long long ans = 0;

bool isMo(char c)
{
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool check(string t, bool isL)
{
	if (!isL)
	{
		return false;
	}

	for (int i = 0; i < t.length() - 2; i++)
	{
		if (isMo(t[i]) && isMo(t[i + 1]) && isMo(t[i + 2]))
		{
			return false;
		}
		if (!isMo(t[i]) && !isMo(t[i + 1]) && !isMo(t[i + 2]))
		{
			return false;
		}
	}
	return true;
}

void go(int idx, bool isL, long long cnt, string t)
{
	if (idx == v.size())
	{
		if (check(t, isL))
		{
			ans += cnt;
		}
		return;
	}

	t[v[idx]] = 'L';
	go(idx + 1, true, cnt, t); // l
	t[v[idx]] = 'A';
	go(idx + 1, isL, cnt == 0 ? 5 : cnt * 5, t); // 모음
	t[v[idx]] = 'B';
	go(idx + 1, isL, cnt == 0 ? 20 : cnt * 20, t); // 자음
}

int main()
{
	cin >> s;
	bool isL = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '_')
		{
			v.push_back(i);
		}
		if (s[i] == 'L')
		{
			isL = true;
		}
	}

	go(0, isL, 0, s);

	cout << ans;
}