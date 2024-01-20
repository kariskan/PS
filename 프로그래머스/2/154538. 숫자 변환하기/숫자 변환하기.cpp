#include <string>
#include <vector>
#include <queue>
using namespace std;
int vis[1000001];
queue<int> q;
int solution(int x, int y, int n) {
    q.push(x);
    vis[x]=1;
    while(!q.empty()){
        int a=q.front();
        q.pop();
        if(a==y){
            return vis[a]-1;
        }
        if(a+n<=1000000&&!vis[a+n]){
            vis[a+n]=vis[a]+1;
            q.push(a+n);
        }
        if(a*2<=1000000&&!vis[a*2]){
            vis[a*2]=vis[a]+1;
            q.push(a*2);
        }
        if(a*3<=1000000&&!vis[a*3]){
            vis[a*3]=vis[a]+1;
            q.push(a*3);
        }
    }
    return -1;
}