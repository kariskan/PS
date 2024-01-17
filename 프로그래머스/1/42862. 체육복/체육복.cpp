#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int l[32];
int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(reserve.begin(),reserve.end());
    int answer = 0;
    for(int i=0;i<lost.size();i++){
        l[lost[i]]=1;
    }
    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            if(lost[i]==reserve[j]){
                l[lost[i]]=0;
                reserve.erase(reserve.begin()+j);
                break;
            }
        }
    }
    for(int i=0;i<reserve.size();i++){
        if(l[reserve[i]-1]){
            l[reserve[i]-1]=0;
            continue;
        }
        if(l[reserve[i]+1]){
            l[reserve[i]+1]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(!l[i]){
            answer++;
        }
    }
    return answer;
}