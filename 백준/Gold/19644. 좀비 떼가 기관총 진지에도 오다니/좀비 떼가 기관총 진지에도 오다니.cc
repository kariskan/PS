#include <iostream>
using namespace std;

long long a[3000001], s[3000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, ml, mk, c;
    cin >> l >> ml >> mk >> c;
    
    for (int i = 1; i <= l; i++) {
        long long now = s[i - 1] - s[max(0, i - ml)];
        cin >> a[i];
        if (a[i] <= now + mk) {
            s[i] = s[i - 1] + mk;
            continue;
        } else {
            if (c) {
                c--;
                s[i] = s[i - 1];
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}
