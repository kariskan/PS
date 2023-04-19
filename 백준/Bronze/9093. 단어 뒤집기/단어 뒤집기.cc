#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        stringstream ss(s);
        string temp;
        vector<string> v;

        while (getline(ss, temp, ' ')) {
            v.push_back(temp);
        }

        for (int j = 0; j < v.size(); j++) {
            reverse(v[j].begin(), v[j].end());
            cout << v[j] << ' ';
        }
        cout << '\n';
    }
}