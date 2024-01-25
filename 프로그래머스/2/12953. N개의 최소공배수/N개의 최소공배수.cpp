#include <string>
#include <vector>

using namespace std;
long long gcd(long long a, long long b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}
int solution(vector<int> arr) {
    long long answer=arr[0];
    for(int i=1;i<arr.size();i++){
        answer=(answer*arr[i])/gcd(answer,arr[i]);
    }
    return answer;
}