#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int l=0,r=0,s=sequence[0];
    while(l<=r&&r<sequence.size()){
        if(s>=k){
            s-=sequence[l];
            l++;
        }else{
            r++;
            if(r<sequence.size()){
                s+=sequence[r];
            }
        }
        if(s==k&&(answer.empty()||answer[1]-answer[0]>r-l)){
            answer={l,r};
        }
    }
    if(answer.empty()){
        return {0,0};
    }
    return answer;
}