#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    vector<long long> a;
    while(n){
        a.push_back(n%10);
        n/=10;
    }
    sort(a.begin(),a.end());
    long long answer=0;
    for(int i=a.size()-1;i>=0;i--){
        answer=answer*10+a[i];
    }
    return answer;
}