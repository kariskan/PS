#include <climits>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long a, b;
        cin >> a >> b;
        while (a != 1) {
            long long left = 2, right = INT_MAX;
            long long ans;
            while (left <= right) {
                long long mid = (left + right) / 2;

                if (a * mid > b) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            a = a * ans - b;
            b = b * ans;
            for (int i = a; i >= 2; i--) {
                if (a % i == 0 && b % i == 0) {
                    a /= i;
                    b /= i;
                }
            }
        }
        cout << b << '\n';
    }
}