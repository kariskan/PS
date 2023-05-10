#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double sum = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int a;
        cin >> a;
        cin >> s;
        cnt += a;
        if (s == "A+") {
            sum += 4.3 * a;
        } else if (s == "A0") {
            sum += 4 * a;
        } else if (s == "A-") {
            sum += 3.7 * a;
        }
        if (s == "B+") {
            sum += 3.3 * a;
        } else if (s == "B0") {
            sum += 3 * a;
        } else if (s == "B-") {
            sum += 2.7 * a;
        }
        if (s == "C+") {
            sum += 2.3 * a;
        } else if (s == "C0") {
            sum += 2 * a;
        } else if (s == "C-") {
            sum += 1.7 * a;
        }
        if (s == "D+") {
            sum += 1.3 * a;
        } else if (s == "D0") {
            sum += 1 * a;
        } else if (s == "D-") {
            sum += 0.7 * a;
        } else {  // F
            sum += 0 * a;
        }
    }

    printf("%.2lf", round((sum / cnt) * 100) / 100);
}