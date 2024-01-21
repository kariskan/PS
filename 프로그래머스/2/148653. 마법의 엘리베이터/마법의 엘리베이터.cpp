#include <string>
#include <vector>
#include <queue>
using namespace std;
int vis[100000001];
queue<int> q;
int solution(int storey) {
    int answer = 0;
    q.push(storey);
    vis[storey]=1;
    
    while(!q.empty()){
        int a=q.front();
        q.pop();
        printf("%d %d\n", a, vis[a]);
        if(a==0){
            return vis[a]-1;
        }
        
        if(!vis[(a+10-a%10)/10]||vis[(a+10-a%10)/10]>vis[a]+10-a%10){
            vis[(a+10-a%10)/10]=vis[a]+10-a%10;
            q.push((a+10-a%10)/10);
        }
        if(!vis[(a-a%10)/10]||vis[(a-a%10)/10]>vis[a]+a%10){
            vis[(a-a%10)/10]=vis[a]+a%10;
            q.push((a-a%10)/10);
        }
    }
    return answer;
}