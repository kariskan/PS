#include <string>
#include <vector>
#include <queue>
using namespace std;
int vis[100000001];
int solution(int storey) {
    int answer = 0;
    queue<int> q;
    q.push(storey);
    vis[storey]=1;

    while(!q.empty()){
        int a=q.front();
        q.pop();
        
        // a/10
        if(!vis[a/10]||vis[a/10]>vis[a]+min(a%10,11-a%10)){
            q.push(a/10);
            vis[a/10]=vis[a]+min(a%10,11-a%10);
        }
        
        // a/10+1
        if(!vis[a/10+1]||vis[a/10+1]>vis[a]+min(a%10+1,10-a%10)){
            q.push(a/10+1);
            vis[a/10+1]=vis[a]+min(a%10+1,10-a%10);
        }
    }
    return vis[0]-1;
}