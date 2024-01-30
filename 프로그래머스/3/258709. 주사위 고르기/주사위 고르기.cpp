#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dice;
vector<int> answer;
int vis[10];
vector<int> redSum,blueSum;
vector<int> red,blue;
void getDiceSumCase(int flag,int idx,int sum){
    if(idx>=red.size()){
        if(!flag){
            redSum.push_back(sum);
        }else{
            blueSum.push_back(sum);
        }
        return;
    }
    for(int i=0;i<6;i++){
        if(!flag){
            getDiceSumCase(flag,idx+1,sum+dice[red[idx]][i]);
        }else{
            getDiceSumCase(flag,idx+1,sum+dice[blue[idx]][i]);
        }
    }
}

void go(int idx,int cnt){
    if(cnt==dice.size()/2){
        red.clear();
        blue.clear();
        for(int i=0;i<dice.size();i++){
            if(vis[i]){
                red.push_back(i);
            }else{
                blue.push_back(i);
            }
        }
        redSum.clear();
        blueSum.clear();
        getDiceSumCase(0,0,0);
        getDiceSumCase(1,0,0);
        sort(redSum.begin(),redSum.end());
        sort(blueSum.begin(),blueSum.end());
        
        int redWinCnt=0;
        for(int i=0;i<redSum.size();i++){
            int r=redSum[i];
            
            int left=0,right=blueSum.size()-1;
            int cnt=0;
            while(left<=right){
                int mid=(left+right)/2;
                
                if(blueSum[mid]<r){
                    cnt=max(cnt,mid);
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
            redWinCnt+=cnt;
        }
        if(answer.empty()||answer[answer.size()-1]<redWinCnt){
            answer.clear();
            for(int i=0;i<red.size();i++){
                answer.push_back(red[i]+1);
            }
            answer.push_back(redWinCnt);
        }
        return;
    }
    if(idx>=dice.size()){
        return;
    }
    go(idx+1,cnt);
    vis[idx]=1;
    go(idx+1,cnt+1);
    vis[idx]=0;
}

vector<int> solution(vector<vector<int>> dice) {
    ::dice=dice;
    go({},0);
    answer.pop_back();
    sort(answer.begin(),answer.end());
    return answer;
}