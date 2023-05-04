#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int n, k;
double a[100000];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    double sum = 0;
    for (int i = k; i < n - k; i++) {
        sum += a[i];
    }
    printf("%.2lf ", round((sum / (n - 2 * k)) * 100) / 100);

    for (int i = 0; i < k; i++) {
        a[i] = a[k];
    }
    for (int i = n - k; i < n; i++) {
        a[i] = a[n - k - 1];
    }

    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    printf("%.2lf", round((sum / n) * 100) / 100);
}