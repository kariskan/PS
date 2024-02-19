#include <string>
#include <vector>

using namespace std;
int vis[100];
int solution(vector<int> cards) {
    int answer = 0;
    vector<int> g;
    for(int i=0;i<cards.size();i++){
        int cnt=0;
        if(!vis[i]){
            int idx=i;
            while(!vis[idx]){
                vis[idx]=1;
                idx=cards[idx]-1;
                cnt++;
            }
            g.push_back(cnt);
        }
    }
    printf("%d",g.size());
    for(int i=0;i<g.size();i++){
        for(int j=0;j<i;j++){
            answer=max(answer,g[i]*g[j]);
        }
    }
    return answer;
}