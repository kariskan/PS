#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end-begin+1);
    for(long long i=begin;i<=end;i++){
        if(i==1){
            continue;
        }
        answer[i-begin]=1;
        for(long long j=2;j*j<=i;j++){
            if(i%j==0){
                answer[i-begin]=max((long long)answer[i-begin],j);
                if(i/j<=10000000){
                    answer[i-begin]=max((long long)answer[i-begin],i/j);
                    break;
                }
            }
        }
    }
    return answer;
}