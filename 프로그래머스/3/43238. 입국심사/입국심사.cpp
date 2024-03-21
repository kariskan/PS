#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left=1,right=(long long)1000000000*1000000000;
    while(left<=right){
        long long mid=(left+right)/2;
        long long cnt=0;
        for(int i=0;i<times.size();i++){
            cnt+=mid/times[i];
        }
        if(cnt>=n){
            right=mid-1;
            answer=mid;
        }else{
            left=mid+1;
        }
    }
    return answer;
}