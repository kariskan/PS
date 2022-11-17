#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int zc = 0, oc = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            zc++;
        else
            oc++;
    }
    zc /= 2, oc /= 2;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            s.erase(s.begin() + i);
            i--;
            oc--;
        }
        if (oc == 0)
            break;
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            s.erase(s.begin() + i);
            i++;
            zc--;
        }
        if (zc == 0)
            break;
    }
    cout << s;
}