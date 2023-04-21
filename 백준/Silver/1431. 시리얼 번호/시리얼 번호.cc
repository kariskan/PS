#include <algorithm>
#include <iostream>
using namespace std;

string arr[50];

bool compare(string& s1, string& s2) {
    if (s1.length() == s2.length()) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] >= '0' && s1[i] <= '9') {
                sum1 += (s1[i] - '0');
            }
            if (s2[i] >= '0' && s2[i] <= '9') {
                sum2 += (s2[i] - '0');
            }
        }
        if (sum1 == sum2) {
            return s1 < s2;
        }
        return sum1 < sum2;
    }
    return s1.length() < s2.length();
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, compare);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
}