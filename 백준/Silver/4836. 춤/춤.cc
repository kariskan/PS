#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		stringstream ss(s);
		vector<string> x;
		string buf;

		int twirl = 0, hop = 0, dip = 0;
		while (getline(ss, buf, ' '))
		{
			if (buf == "twirl")
			{
				twirl = 1;
			}
			if (buf == "hop")
			{
				hop = 1;
			}
			if (buf == "dip")
			{
				dip = 1;
			}
			x.push_back(buf);
		}
		int one = 1, two = 1, three = 1, four = 1, five = 1, siz = x.size();

		if (siz < 3 || !(x[siz - 1] == "clap" && x[siz - 2] == "stomp" && x[siz - 3] == "clap"))
		{
			two = 0;
		}
		if (x[0] == "jiggle")
		{
			four = 0;
		}
		if (!dip)
		{
			five = 0;
		}
		if (twirl && !hop)
		{
			three = 0;
		}
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == "dip")
			{
				if (!((i > 0 && x[i - 1] == "jiggle") || (i > 1 && x[i - 2] == "jiggle") || (i < siz - 1 && x[i + 1] == "twirl")))
				{
					x[i] = "DIP";
					one = 0;
				}
			}
		}

		if (one && two && three && four && five)
		{
			cout << "form ok: " + s << '\n';
		}
		else
		{
			int cnt = 0;
			vector<int> v;
			if (!one)
				cnt++, v.push_back(1);
			if (!two)
				cnt++, v.push_back(2);
			if (!three)
				cnt++, v.push_back(3);
			if (!four)
				cnt++, v.push_back(4);
			if (!five)
				cnt++, v.push_back(5);
			if (cnt == 1)
			{
				cout << "form error " << v[0] << ": ";
				for (int i = 0; i < x.size(); i++)
				{
					cout << x[i] << " ";
				}
				cout << '\n';
			}
			else
			{
				cout << "form errors ";
				for (int i = 0; i < v.size(); i++)
				{
					cout << v[i];
					if (i == v.size() - 2)
					{
						cout << " and ";
					}
					else if (i < v.size() - 2)
					{
						cout << ", ";
					}
				}
				cout << ": ";
				for (int i = 0; i < x.size(); i++)
				{
					cout << x[i] << " ";
				}
				cout << '\n';
			}
		}
	}
}
