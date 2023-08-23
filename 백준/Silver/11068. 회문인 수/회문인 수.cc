#include <iostream>
#include <vector>
using namespace std;

vector<int> get(int n, int b) {
    vector<int> res;
    while (n) {
        res.push_back(n % b);
        n /= b;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        bool flag1 = false;
        for (int i = 2; i <= 64; i++) {
            vector<int> res = get(a, i);
            bool flag2 = true;
            for (int i = 0; i < res.size() / 2; i++) {
                if (res[i] != res[res.size() - i - 1]) {
                    flag2 = false;
                    break;
                }
            }
            if (flag2) {
                flag1 = true;
                break;
            }
        }
        if (flag1) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}