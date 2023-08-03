#include <iostream>
#include <map>
using namespace std;

int n, a[500];
map<int, int> m, diff;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
        if (i > 0) {
            diff[a[i] - a[i - 1]]++;
        }
    }
    int ans = 500;
    for (auto &i : m) {
        ans = min(ans, n - i.second);
    }
    
    for (int i = 1; i < n; i++) {
        int diff = a[i] - a[i - 1];
        int pre = a[i];
        int temp = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] - pre != diff) {
                pre = a[j - 1] + diff;
                temp++;
            }
        }
        pre = a[i - 1];
        for (int j = i - 2; j >= 0; j--) {
            if (a[j + 1] - a[j] != diff) {
                pre = a[j + 1] - diff;
                temp++;
            }
        }
        ans = min(ans, temp);
    }
    
    cout << ans;
}