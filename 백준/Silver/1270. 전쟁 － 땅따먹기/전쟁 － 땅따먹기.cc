#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        map<long long, int> ma;
        int t;
        cin >> t;
        long long ans = -1;
        for (int j = 0; j < t; j++) {
            long long a;
            cin >> a;
            ma[a]++;
            if (ma[a] > t / 2) {
                ans = a;
            }
        }
        if (ans != -1) {
            cout << ans << '\n';
        } else {
            cout << "SYJKGW\n";
        }
    }
}