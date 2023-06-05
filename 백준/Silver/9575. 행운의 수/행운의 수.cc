#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> a, b, c;
        set<int> se;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            a.push_back(k);
        }
        cin >> n;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            b.push_back(k);
        }
        cin >> n;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            c.push_back(k);
        }

        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                for (int k = 0; k < c.size(); k++) {
                    int sum = a[i] + b[j] + c[k];
                    bool flag = true;
                    int temp = sum;
                    while (sum) {
                        if (sum % 10 != 5 && sum % 10 != 8) {
                            flag = false;
                            break;
                        }
                        sum /= 10;
                    }
                    if (flag) {
                        se.insert(temp);
                    }
                }
            }
        }
        cout << se.size() << '\n';
    }
}