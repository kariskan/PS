#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,m,vis[50][50];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<vector<int>> rotate(vector<vector<int>> r){
    vector<vector<int>> res(r[0].size(),vector<int>(r.size()));
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            res[i][j]=r[j][res.size()-i-1];
        }
    }
    return res;
}

vector<vector<vector<int>>> dfs(vector<vector<int>> board,int flag){
    memset(vis,0,sizeof(vis));
    vector<vector<vector<int>>> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==flag&&!vis[i][j]){
                queue<pair<int,int>> temp,q;
                
                q.push({i,j});
                vis[i][j]=1;
                
                int minx=n,miny=m,maxx=0,maxy=0;
                
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    
                    temp.push({x,y});
                    minx=min(minx,x);
                    miny=min(miny,y);
                    maxx=max(maxx,x);
                    maxy=max(maxy,y);
                    
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&board[nx][ny]==flag){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
                
                vector<vector<int>> insert(maxx-minx+1,vector<int>(maxy-miny+1));
                while(!temp.empty()){
                    int x=temp.front().first;
                    int y=temp.front().second;
                    temp.pop();
                    insert[x-minx][y-miny]=1;
                }
                v.push_back(insert);
            }
        }
    }
    return v;
}

bool check(vector<vector<int>> v1,vector<vector<int>> v2){
    for(int r=0;r<4;r++){
        v2=rotate(v2);
        if(v1.size()!=v2.size()||v1[0].size()!=v2[0].size()){
            continue;
        }
        bool flag=true;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v1[0].size();j++){
                if(v1[i][j]!=v2[i][j]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            return true;
        }
    }
    return false;
}

int solution(vector<vector<int>> board, vector<vector<int>> table) {
    n=board.size(),m=board[0].size();
    vector<vector<vector<int>>> bp=dfs(board,0);
    vector<vector<vector<int>>> tp=dfs(table,1);
    
    int answer=0;
    vector<int> tpVis(tp.size());
    for(int i=0;i<bp.size();i++){
        for(int j=0;j<tp.size();j++){
            if(tpVis[j]){
                continue;
            }
            if(check(bp[i],tp[j])){
                for(int i1=0;i1<tp[j].size();i1++){
                    for(int j1=0;j1<tp[j][0].size();j1++){
                        if(tp[j][i1][j1]==1){
                            answer++;
                        }
                    }
                }
                tpVis[j]=1;
                break;
            }
        }
    }
    return answer;
}