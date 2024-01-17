#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

vector<int> solution(int n, int m) {
    return {gcd(n,m),(int)(((long long)n*(long long)m)/gcd(n,m))};
}