#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> se;
    se.insert("ChongChong");

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (se.find(s1) != se.end()) {
            se.insert(s2);
        }
        if (se.find(s2) != se.end()) {
            se.insert(s1);
        }
    }

    cout << se.size();
}