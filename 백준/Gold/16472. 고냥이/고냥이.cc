#include <iostream>
using namespace std;

int n;
string s;

int main()
{
	cin >> n >> s;
	int left = 0, right = 0;
	int alpha[26] = {
		0,
	};
	int ans = 1, cnt = 1;
	alpha[s[0] - 'a'] = 1;
	while (left <= right && right < s.length())
	{
		while (1)
		{
			right++;
			if (!alpha[s[right] - 'a'])
			{
				cnt++;
			}
			alpha[s[right] - 'a']++;

			if (cnt > n || right >= s.length())
			{
				break;
			}

			ans = max(ans, right - left + 1);
		}

		while (cnt > n)
		{
			alpha[s[left] - 'a']--;
			left++;
			if (alpha[s[left - 1] - 'a'] == 0)
			{
				cnt--;
			}

			if (cnt <= n)
			{
				ans = max(ans, right - left + 1);
				break;
			}
		}
	}

	cout << ans;
}