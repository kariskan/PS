#include <iostream>
using namespace std;

int main() {
	
    int n;
    cin >> n;
    long long ans = 1;
    while (n >= 5) {
    	ans = (ans * 3) % 10007;
        n -= 3;
    }
    
    ans = (ans * n) % 10007;
    cout << ans;
}