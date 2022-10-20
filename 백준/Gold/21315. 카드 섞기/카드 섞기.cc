#include <iostream>
#include <deque>
using namespace std;

int n;
deque<int> ans, d;

deque<int> go(int k1, deque<int> a)
{
    deque<int> temp = a, temp2;
    for (int i = 1; i <= k1 + 1; i++)
    {
        int tSize = temp.size();
        deque<int> temp3;
        for (int j = 0; j < tSize - (1 << (k1 - i + 1)); j++)
        {
            temp3.push_front(temp.front());
            temp.pop_front();
        }
        while(!temp3.empty()){
            temp2.push_front(temp3.front());
            temp3.pop_front();
        }
        for (int j = 0; j < (1 << (k1 - i + 1)); j++)
        {
            int a = temp.back();
            temp.pop_back();
            temp.push_front(a);
        }
    }
    while (!temp2.empty())
    {
        temp.push_back(temp2.front());
        temp2.pop_front();
    }

    return temp;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ans.push_back(a);
        d.push_back(i + 1);
    }

    for (int k1 = 1; (1 << k1) < n; k1++)
    {
        for (int k2 = 1; (1 << k2) < n; k2++)
        {
            deque<int> temp = d;
            temp = go(k1, temp);
            temp = go(k2, temp);

            int ok = 1;
            for (int i = 0; i < n; i++)
            {
                if (temp[i] != ans[i])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                cout << k1 << ' ' << k2;
                return 0;
            }
        }
    }
}