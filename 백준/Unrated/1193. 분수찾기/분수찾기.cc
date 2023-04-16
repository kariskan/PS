#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1;; i++) {
        if (sum + i >= n) {
            if (i % 2 == 0) {
                cout << n - sum << "/" << i + 1 - n + sum;
            } else {
                cout << i + 1 - n + sum << "/" << n - sum;
            }
            break;
        }
        sum += i;
    }
}