#include <set>
#include <iostream>
#include <vector>
using namespace std;

set<char> se;

vector<string> parsed(string s)
{
    string res = "";
    vector<string> ret;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ret.push_back(res);
            res = "";
            continue;
        }
        res += s[i];
    }
    if (!res.empty())
        ret.push_back(res);
    return ret;
}

bool go(char c)
{
    int a;
    if (c >= 'a' && c <= 'z')
    {
        a = c - 'a';
    }
    else
    {
        a = c - 'A';
    }

    return se.find(a + 'a') == se.end() && se.find(a + 'A') == se.end();
}

int main()
{
    int n;
    cin >> n;
    cin.get();

    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        vector<string> v = parsed(s);
        int ok = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (go(v[j][0]))
            {
                for(int k=0;k<j;k++){
                    cout<<v[k]<<' ';
                }
                se.insert(v[j][0]);
                cout << "[" << v[j][0] << "]";
                for (int k = 1; k < v[j].size(); k++)
                {
                    cout << v[j][k];
                }
                cout << ' ';
                for (int k = j + 1; k < v.size(); k++)
                {
                    cout << v[k] << ' ';
                }
                ok = 1;
                break;
            }
        }
        if (!ok)
        {
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] == ' ')
                {
                    cout << ' ';
                    continue;
                }
                if (go(s[j]))
                {
                    se.insert(s[j]);
                    cout << "[" << s[j] << "]";
                    for(int k=j+1;k<s.length();k++){
                        cout<<s[k];
                    }
                    break;
                }
                cout << s[j];
            }
        }
        cout<<'\n';
    }
}