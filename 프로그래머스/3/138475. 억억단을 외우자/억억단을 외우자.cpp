#include <string>
#include <vector>

using namespace std;
int cnt[5000001],ans[5000001];
vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    for(int i=1;i<=e;i++){
        for(int j=i;j<=e;j+=i){
            cnt[j]++;
        }
    }
    int ma=0,idx=e;
    for(int i=e;i>=1;i--){
        if(ma<=cnt[i]){
            ma=cnt[i];
            idx=i;
        }
        ans[i]=idx;
    }
    for(int start:starts){
        answer.push_back(ans[start]);
    }
    return answer;
}