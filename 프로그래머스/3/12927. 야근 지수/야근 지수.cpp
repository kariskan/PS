#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long sum=0;
    sort(works.begin(),works.end());
    for(int i=0;i<works.size();i++){
        sum+=works[i];
    }
    sum=max((long long)0,sum-n); // 6
    for(int i=0;i<works.size();i++){
        long long k = sum / (works.size()-i);
        if (k>works[i]){
            answer += works[i] * works[i];
            sum -= works[i];
            continue;
        }
        sum -= k;
        answer += k * k;
    }
    return answer;
}