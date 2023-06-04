#include <iostream>
using namespace std;

int a[100000];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += a[i];
    }
    int temp = sum;
    for (int i = 1; i < n; i++) {
        temp = temp - a[i - 1] + a[(i + m - 1) % n];
        sum = max(sum, temp);
    }
    cout << sum;
}