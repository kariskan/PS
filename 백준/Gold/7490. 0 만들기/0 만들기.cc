#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<string> v;

bool check(vector<char> op)
{
    vector<int> num = {1};
    for (int i = 0; i < op.size(); i++)
    {
        if (op[i] == ' ')
        {
            int t = num.back() * 10 + i + 2;
            num.pop_back();
            num.push_back(t);
        }
        else
        {
            num.push_back(i + 2);
        }
    }
    int s = num[0], k = 0;
    for (int i = 0; i < op.size(); i++)
    {
        if (op[i] == '+')
        {
            s += num[i + 1 - k];
        }
        else if (op[i] == '-')
        {
            s -= num[i + 1 - k];
        }
        else
        {
            k++;
            continue;
        }
    }
    return s == 0;
}

void go(int idx, int n, vector<char> op)
{
    if (op.size() == n - 1)
    {
        if (check(op))
        {
            string ans = "1";
            for (int i = 1; i < n; i++)
            {
                ans += op[i - 1];
                ans += (i + 1 + '0');
            }
            v.push_back(ans);
        }
        return;
    }
    op.push_back(' ');
    go(idx, n, op);
    op.pop_back();
    op.push_back('+');
    go(idx, n, op);
    op.pop_back();
    op.push_back('-');
    go(idx, n, op);
    op.pop_back();
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        v.clear();
        int n;
        cin >> n;
        go(i, n, {});
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[j] << '\n';
        }
        cout << '\n';
    }
}