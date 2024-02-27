#include <string>
#include <vector>

using namespace std;
bool isPrime(int idx){
    if(idx==0||idx==1){
        return false;
    }
    for(int i=2;i*i<=idx;i++){
        if(idx%i==0){
            return false;
        }
    }
    return true;
}
int getBlock(int idx){
    if(idx==1){
        return 0;
    }
    if(isPrime(idx)){
        return 1;
    }
    int res=0;
    for(int i=2;i*i<=idx;i++){
        if(idx%i==0&&idx/i>=2&&idx/i<=10000000){
            res=max(res,idx/i);
        }
        if(idx%i==0&&i>=2&&i<=10000000){
            res=max(res,i);
        }
    }
    return res;
}
vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(int i=begin;i<=end;i++){
        answer.push_back(getBlock(i));
    }
    return answer;
}