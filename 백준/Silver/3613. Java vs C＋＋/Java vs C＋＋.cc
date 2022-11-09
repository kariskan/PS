#include <iostream>
#include <string>
using namespace std;

bool checkC(string s)
{
    if (s[0] == '_' || s[s.length() - 1] == '_')
    {
        return false;
    }
    if (s.find("__") != string::npos)
    {
        return false;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (!((s[i] >= 'a' && s[i] <= 'z') || s[i] == '_'))
        {
            return false;
        }
    }
    return true;
}
bool checkJ(string s)
{
    if (s[0] >= 'A' && s[0] <= 'Z')
    {
        return false;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
        {
            return false;
        }
    }
    return true;
}

int main()
{

    string s;
    cin >> s;
    string ans = "";
    ans += s[0];
    if (!checkC(s) && !checkJ(s))
    {
        cout << "Error!";
        return 0;
    }
    if (s.find("_") != string::npos)
    {
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == '_')
            {
                ans += (s[i + 1] - 'a' + 'A');
                i++;
            }
            else
            {
                ans += s[i];
            }
        }
    }
    else
    {
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                ans += '_';
                ans += (s[i] - 'A' + 'a');
            }
            else
            {
                ans += s[i];
            }
        }
    }
    cout << ans;
}