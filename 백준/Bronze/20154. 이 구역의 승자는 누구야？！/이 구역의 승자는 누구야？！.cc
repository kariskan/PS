#include <iostream>
#include <queue>
using namespace std;

int c[26] = {3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};
queue<int> q;
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		q.push(c[s[i] - 'A']);
	}
	while (q.size() != 1)
	{
		int qsize = q.size();
		queue<int> q2;
		while (!q.empty())
		{
			if (q.size() >= 2)
			{
				int a = q.front();
				q.pop();
				a += q.front();
				q.pop();
				a %= 10;
				q2.push(a);
			}
			else
			{
				int a = q.front();
				q.pop();
				q2.push(a);
			}
		}
		q = q2;
		
	}
	if (q.front() % 2 == 1)
	{
		cout << "I'm a winner!";
	}
	else
	{
		cout << "You're the winner?";
	}
}