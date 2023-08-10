#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    int t = 0;
    while (1) {
        t++;
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        set<int> se;
        map<int, string> ma;
        getchar();
        for (int i = 0; i < n; i++) {
            string s;
            getline(cin, s);
            ma[i + 1] = s;
        }
        for (int i = 0; i < n * 2 - 1; i++) {
            int a;
            string s;
            cin >> a >> s;
            if (se.find(a) == se.end()) {
                se.insert(a);
            } else {
                se.erase(a);
            }
        }
        
        for (auto &i : se) {
            cout << t << ' ' << ma[i] << '\n';
        }
    }
}