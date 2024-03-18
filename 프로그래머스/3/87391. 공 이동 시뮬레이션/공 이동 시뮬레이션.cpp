#include <string>
#include <vector>

using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
long long solution(int n, int m, int x, int y, vector<vector<int>> query) {
    int sx=x,sy=y,ex=x,ey=y;
    for(int i=query.size()-1;i>=0;i--){
        if(query[i][0]==0){
            if(sy==0){
                ey=min(m-1,ey+query[i][1]);
            }else{
                if(sy+query[i][1]>=m){
                    return 0;
                }
                sy=min(m-1,sy+query[i][1]);
                ey=min(m-1,ey+query[i][1]);
            }
        }else if(query[i][0]==1){
            if(ey==m-1){
                sy=max(0,sy-query[i][1]);
            }else{
                if(ey-query[i][1]<0){
                    return 0;
                }
                sy=max(0,sy-query[i][1]);
                ey=max(0,ey-query[i][1]);
            }
        }else if(query[i][0]==2){
            if(sx==0){
                ex=min(n-1,ex+query[i][1]);
            }else{
                if(sx+query[i][1]>=n){
                    return 0;
                }
                sx=min(n-1,sx+query[i][1]);
                ex=min(n-1,ex+query[i][1]);
            }
        }else{
            if(ex==n-1){
                sx=max(0,sx-query[i][1]);
            }else{
                if(ex-query[i][1]<0){
                    return 0;
                }
                sx=max(0,sx-query[i][1]);
                ex=max(0,ex-query[i][1]);
            }
        }
        // printf("%d %d %d %d\n", sx,sy,ex,ey);
    }
    
    return ((long long)ex-sx+1)*((long long)ey-sy+1);
}