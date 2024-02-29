#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dice;
vector<int> answer,A,B;
int vis[10],maxWinCnt;

void numberChoose(vector<int> diceNum,int idx,int sum,int flag){
    if(idx==diceNum.size()){
        if(flag==0){
            A.push_back(sum);
        }else{
            B.push_back(sum);
        }
        return;
    }
    
    for(int i=0;i<6;i++){
        numberChoose(diceNum,idx+1,sum+dice[diceNum[idx]][i],flag);
    }
}
void diceChoose(vector<int> diceNumA, int idx){
    if(diceNumA.size()==dice.size()/2){
        A.clear(), B.clear();
        
        vector<int> diceNumB;
        for(int i=0;i<dice.size();i++){
            if(!vis[i]){
                diceNumB.push_back(i);
            }
        }
        
        numberChoose(diceNumA,0,0,0);
        numberChoose(diceNumB,0,0,1);
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        int totalWinCnt=0;
        for(int i=0;i<A.size();i++){
            int left=0,right=B.size()-1;
            int winCnt=0;
            
            while(left<=right){
                int mid=(left+right)/2;
                
                if(B[mid]<A[i]){
                    left=mid+1;
                    winCnt=mid+1;
                }else{
                    right=mid-1;
                }
            }
            
            totalWinCnt+=winCnt;
        }
        if(maxWinCnt<totalWinCnt){
            maxWinCnt=totalWinCnt;
            for(int i=0;i<diceNumA.size();i++){
                answer[i]=diceNumA[i]+1;
            }
        }
        
        return;
    }
    if(idx>=dice.size()){
        return;
    }
    
    diceChoose(diceNumA,idx+1);
    diceNumA.push_back(idx);
    vis[idx]=1;
    diceChoose(diceNumA,idx+1);
    vis[idx]=0;
}

vector<int> solution(vector<vector<int>> dice) {
    ::dice=dice;
    answer.resize(dice.size()/2);
    diceChoose({},0);
    return answer;
}