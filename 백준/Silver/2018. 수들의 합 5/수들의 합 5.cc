#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int left = 0, right = 0, sum = 0, ans = 0;
    while (left <= right)
    {
        if (sum == n)
        {
            ans++;
            right++;
            sum += right;
        }
        else if (sum > n)
        {
            sum -= left;
            left++;
        }
        else
        {
            right++;
            sum += right;
        }
    }
    
    cout << ans;
}