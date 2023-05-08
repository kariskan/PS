#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (c % 2 ? a ^ b : a);
}