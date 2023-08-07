#include <iostream>
#include <vector>
using namespace std;

int main() {
    int g = 1;
    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        pair<string, vector<string>> p[20];
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            p[i].first = s;
            for (int j = 0; j < n - 1; j++) {
                string t;
                cin >> t;
                p[i].second.push_back(t);
            }
        }
        cout << "Group " << g++ << '\n';
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (p[i].second[j] == "N") {
                    int target = (i + n - (j + 1)) % n;
                    cout << p[target].first << " was nasty about " << p[i].first
                         << '\n';
                    flag = true;
                }
            }
        }
        if (!flag) {
            cout << "Nobody was nasty\n";
        }
        cout << '\n';
    }
}