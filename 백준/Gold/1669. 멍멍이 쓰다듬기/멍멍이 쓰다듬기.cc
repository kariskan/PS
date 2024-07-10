#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

long long sumAToB(long long a, long long b) {
    if (a == 1) {
        return (b * (b + 1)) / 2;
    }
    return sumAToB(1, b) - sumAToB(1, a - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a,b;
    cin>>a>>b;
    for(long long i=0;i<=100000;i++) {
        long long maxSum = sumAToB(1, i) + sumAToB(1, i - 1);
        if (maxSum >= b - a) {
            long long nowSum = 0;
            long long start = 1;
            int cnt = 0;
            while (nowSum < b - a) {
                nowSum += start;
                cnt++;

                long long r = b - a - nowSum;
                if (sumAToB(1, start + 1) <= r) {
                    start++;
                } else if (sumAToB(1, start) > r) {
                    start--;
                }
            }
            cout << cnt;
            return 0;
        }
    }
}
