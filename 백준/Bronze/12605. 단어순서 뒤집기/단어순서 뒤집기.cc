#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);

        stringstream ss(s);
        vector<string> v;
        string temp;
        while (getline(ss, temp, ' ')) {
            v.push_back(temp);
        }
        cout << "Case #" << i << ": ";
        for (int i = v.size() - 1; i >= 0; i--) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
}