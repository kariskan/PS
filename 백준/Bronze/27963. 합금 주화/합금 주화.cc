#include <iostream>
using namespace std;

double d1, d2, x;

int main() {
    cin >> d1 >> d2 >> x;

    if (d1 < d2) {
        swap(d1, d2);
    }

	printf("%.7lf", 100 / (x / d1 + (100 - x) / d2));
}