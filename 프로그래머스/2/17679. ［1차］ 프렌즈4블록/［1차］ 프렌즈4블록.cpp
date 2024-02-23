#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dx[3]={0,1,1};
int dy[3]={1,0,1};
int solution(int n, int m, vector<string> board) {
    int answer = 0;
    while(1){
        vector<pair<int,int>> v;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                if(board[i][j]==' '){
                    continue;
                }
                bool flag2=true;
                for(int k=0;k<3;k++){
                    if(board[i][j]!=board[i+dx[k]][j+dy[k]]){
                        flag2=false;
                        break;
                    }
                }
                if(flag2){
                    v.push_back({i,j});
                    for(int k=0;k<3;k++){
                        v.push_back({i+dx[k],j+dy[k]});
                    }
                }
            }
        }
        
        if(v.empty()){
            break;
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        answer+=v.size();
        
        for(int i=0;i<v.size();i++){
            board[v[i].first][v[i].second]=' ';
        }
        for(int j=0;j<m;j++){
            for(int i=n-1;i>=0;i--){
                if(board[i][j]==' '){
                    int idx=i;
                    while(idx>=0&&board[idx][j]==' '){
                        idx--;
                    }
                    if(idx>=0){
                        board[i][j]=board[idx][j];
                        board[idx][j]=' ';
                    }
                }
            }
        }
    }
    return answer;
}