#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n, m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<double> inp;
        cin >> m;
        double sum = 0;
        for (int j = 0; j < m; j++) {
            double a;
            cin >> a;
            inp.push_back(a);
            sum += a;
        }
        sum /= m;
        double ans = 0;
        for (int j = 0; j < m; j++) {
            if (inp[j] > sum) {
                ans++;
            }
        }
        ans = round(((ans / m) * 100 * 1000)) / 1000;
        printf("%0.3lf", ans);
		cout<<"%\n";
    }
}