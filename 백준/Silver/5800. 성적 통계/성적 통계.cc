#include <algorithm>
#include <iostream>
using namespace std;

int a[100][50];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int l = 0;
            cin >> l;
            a[i][j] = l;
        }
        sort(a[i], a[i] + k);
        int l = 0;
        for (int j = 1; j < k; j++) {
            l = max(l, a[i][j] - a[i][j - 1]);
        }
        cout << "Class " << i + 1 << '\n' << "Max " << a[i][k - 1] << ", Min " << a[i][0] << ", Largest gap " << l << '\n';
    }
}