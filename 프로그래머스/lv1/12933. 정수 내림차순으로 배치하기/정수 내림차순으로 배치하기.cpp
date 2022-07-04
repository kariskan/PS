#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(long long a, long long b) {
    return a > b;
}
long long solution(long long n) {
    long long answer = 0;
    vector<long long> v;
    while(n) {
        v.push_back(n%10);
        n/=10;
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0;i<v.size();i++){
        answer = answer * 10 + v[i];
    }
    return answer;
}