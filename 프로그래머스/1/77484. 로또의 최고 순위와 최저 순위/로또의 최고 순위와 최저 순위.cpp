#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt=0, zero=0;
    for(int i=0;i<6;i++){
        if(lottos[i]==0){
            zero++;
        }
        for(int j=0;j<6;j++){
            if(lottos[i]==win_nums[j]){
                cnt++;
                break;
            }
        }
    }
    
    return {7-min(6,cnt+zero)==7?6:7-min(6,cnt+zero),min(6,7-cnt)};
}