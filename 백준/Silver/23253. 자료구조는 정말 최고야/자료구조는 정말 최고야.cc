#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        int pre = 200001;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            if (a > pre) {
                cout << "No";
                return 0;
            }
            pre = a;
        }
    }
    cout << "Yes";
}