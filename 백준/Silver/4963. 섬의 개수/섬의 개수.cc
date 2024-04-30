#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int dx[8]={0,0,1,-1, 1,1,-1,-1};
    int dy[8]={1,-1,0,0,1,-1,1,-1};
    while (1) {
        int w=-1,h;
        cin>>w>>h;
        if(w==0&&h==0){
            break;
        }
        int map[50][50]={0,},vis[50][50]={0,};
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>map[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(map[i][j]&&!vis[i][j]){
                    ans++;
                    vis[i][j]=1;
                    queue<pair<int,int>> q;

                    q.push({i,j});

                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
//                        cout<<x<<' '<<y<<'\n';
                        q.pop();

                        for(int k=0;k<8;k++){
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            if(nx>=0&&nx<h&&ny>=0&&ny<w&&!vis[nx][ny]&&map[nx][ny]){
                                vis[nx][ny]=1;
                                q.push({nx,ny});
                            }
                        }
                    }
//                    cout<<'\n';
                }
            }
        }
        cout<<ans<<'\n';
    }
}