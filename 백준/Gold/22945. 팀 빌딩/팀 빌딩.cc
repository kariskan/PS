#include <iostream>
using namespace std;
int a[100000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int left = 0, right = n - 1, ans = 0;
    while (left < right) {
        ans = max(ans, min(a[left], a[right]) * (right - left - 1));
        if (a[left] < a[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << ans;
}