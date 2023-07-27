#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    map<string, int> ma;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == s) {
            cout << ma[s2];
            return 0;
        }
        ma[s2]++;
    }
}