#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer={0,(int)sequence.size()-1};
    int left=0,right=0,sum=sequence[0];
    while(right<sequence.size()){
        if(sum<k){
            sum+=sequence[++right];
        }else{
            if(sum==k){
                if(answer[1]-answer[0]>right-left){
                    answer={left,right};
                }
            }
            sum-=sequence[left++];
        }
    }
    return answer;
}