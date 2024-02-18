#include <string>
#include <vector>
#include <queue>
using namespace std;
int vis[100000001],b[18]={-100000000,-10000000,-1000000,-100000,-10000,-1000,-100,-10,-1,1,10,100,1000,10000,100000,1000000,10000000,100000000};
int solution(int storey) {
    int answer = 0;
    queue<int> q;
    q.push(storey);
    vis[storey]=1;
    
    while(!q.empty()){
        int a=q.front();
        q.pop();
        if(a==0){
            return vis[a]-1;
        }
        
        for(int i=0;i<18;i++){
            if(a+b[i]>=0&&a+b[i]<=100000000&&!vis[a+b[i]]){
                vis[a+b[i]]=vis[a]+1;
                q.push(a+b[i]);
            }
        }
    }
}