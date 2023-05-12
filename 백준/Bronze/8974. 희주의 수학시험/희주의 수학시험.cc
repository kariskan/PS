#include <iostream>
using namespace std;

int a[1001];

int main() {
    int idx = 1, idx2 = 0;
    for (int i = 1; i <= 1000; i++) {
        a[i] = idx;
        idx2++;
        if (idx2 == idx) {
            idx++;
            idx2 = 0;
        }
    }
    int a1, b;
    cin >> a1 >> b;
    int sum = 0;
    for (int i = a1; i <= b; i++) {
        sum += a[i];
    }
    cout << sum;
}