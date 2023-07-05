#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    double bad = 0, good = 0;
    if (m == 0) {
        good = 1;
    } else {
        bad = 1;
    }

    double gg, gb, bg, bb;
    cin >> gg >> gb >> bg >> bb;
    while (n--) {
        double tempGood = good;
        double tempBad = bad;
        
        good = tempGood * gg + tempBad * bg;
        bad = tempGood * gb + tempBad * bb;
    }
    cout << round(good * 1000) << '\n' << round(bad * 1000);
}