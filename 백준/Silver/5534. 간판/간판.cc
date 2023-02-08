#include <iostream>
using namespace std;

int n, ans;
string s, a;

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		for (int j = 0; j < a.length(); j++) // j는 시작 지점
		{
			int ok = 0;
			for (int jump = 0; jump < a.length(); jump++) // jump는 간격
			{
				string t = "";
				// k: jump만큼의 간격의 문자를 더하고, 최대 cnt 만큼 더한다.
				for (int k = j, cnt = 0; cnt < s.length() && k < a.length(); cnt++, k += jump)
				{
					t += a[k];
				}
				if (t == s)
				{
					ans++;
					ok = 1;
					break;
				}
			}
			if (ok)
			{
				break;
			}
		}
	}
	
	cout << ans;
}