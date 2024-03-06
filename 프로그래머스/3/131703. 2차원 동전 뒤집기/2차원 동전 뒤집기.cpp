#include <string>
#include <vector>

using namespace std;
int n,m,answer=-1;
vector<vector<int>> beginning, target;

// flag==0일때 가로 뒤집기, 1일때 세로 뒤집기
vector<vector<int>> flap(vector<int> v){
    vector<vector<int>> res=beginning;
    
    for(int i=0;i<v.size();i++){
        int idx=v[i];
        for(int j=0;j<m;j++){
            res[idx][j]=1-res[idx][j];
        }
    }
    return res;
}

void go(vector<int> now, int idx){
    if(idx==n){
        vector<vector<int>> res=flap(now);
        int totalCnt=now.size();
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(res[i][j]!=target[i][j]){
                    cnt++;
                }
            }
            if(cnt>0&&cnt<n){
                return;
            }
            if(cnt==0){
                continue;
            }
            totalCnt++;
        }
        if(answer==-1||answer>totalCnt){
            answer=totalCnt;
        }
        return;
    }
    
    go(now,idx+1);
    now.push_back(idx);
    go(now,idx+1);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    ::beginning=beginning;
    ::target=target;
    n=beginning.size(),m=beginning[0].size();
    go({},0);
    return answer;
}