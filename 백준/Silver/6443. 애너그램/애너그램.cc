#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool compare(string s1, string s2)
{
    if (s1.length() == s2.length())
    {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());

    set<string> s;

    for (int i = 0; i < v.size(); i++)
    {
        string now = v[i];
        sort(now.begin(), now.end());

        do
        {
            s.insert(now);
        } while (next_permutation(now.begin(), now.end()));
    }
    v.clear();
    for (auto &i : s)
    {
        v.push_back(i);
    }
    sort(v.begin(), v.end(), compare);
    for (auto &i : v)
    {
        cout << i << '\n';
    }
}