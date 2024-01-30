#include <string>
#include <vector>
#include <queue>
using namespace std;
int vis[200];
vector<vector<int>> v;
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            answer++;
            vis[i]=1;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int j=0;j<n;j++){
                    if(!vis[j]&&computers[node][j]){
                        vis[j]=1;
                        q.push(j);
                    }
                }
            }
        }
    }
    return answer;
}