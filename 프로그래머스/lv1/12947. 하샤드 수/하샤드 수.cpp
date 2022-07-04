#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int t = x;
    int div = 0;
    while(t) {
        div += t%10;
        t/=10;
    }
    return x%div?false:true;
}