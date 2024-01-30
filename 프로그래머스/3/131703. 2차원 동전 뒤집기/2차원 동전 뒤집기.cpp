#include <string>
#include <vector>

using namespace std;

int row[10],col[10];
int n,m, answer=-1;
vector<vector<int>> b,t;
vector<vector<int>> temp;
void flap(int rc, int idx){
    if(rc==0){ // 행
        for(int j=0;j<m;j++){
            temp[idx][j]=1-temp[idx][j];
        }
    }else{
        for(int i=0;i<n;i++){
            temp[i][idx]=1-temp[i][idx];
        }
    }
}
void go(int rowIdx, int colIdx, int cnt) {
    if(rowIdx>=n&&colIdx>=m){
        temp=b;
        for(int i=0;i<n;i++){
            if(row[i]){
                flap(0,i);
            }
        }
        for(int i=0;i<m;i++){
            if(col[i]){
                flap(1,i);
            }
        }
        
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]!=t[i][j]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            if(answer==-1||answer>cnt){
                answer=cnt;
            }
        }
        return;
    }
    
    if(rowIdx<n){
        go(rowIdx+1,colIdx,cnt);
        row[rowIdx]=1;
        go(rowIdx+1,colIdx,cnt+1);
        row[rowIdx]=0;
    }else{
        go(rowIdx,colIdx+1,cnt);
        col[colIdx]=1;
        go(rowIdx,colIdx+1,cnt+1);
        col[colIdx]=0;
    }
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    b=beginning;
    t=target;
    n=b.size();
    m=b[0].size();
    go(0,0,0);
    return answer;
}