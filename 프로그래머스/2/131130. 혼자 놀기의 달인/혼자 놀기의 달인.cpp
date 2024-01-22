#include <string>
#include <vector>
#include <queue>
using namespace std;

int vis[101];

int solution(vector<int> cards) {
    int answer = 0;
    priority_queue<int> q;
    for(int i=0;i<cards.size();i++){
        if(vis[i]){
            continue;
        }
        vis[i]=1;
        int idx = cards[i]-1;
        int s = 1;
        while(idx!=i){
            s++;
            vis[idx]=1;
            idx=cards[idx]-1;
        }
        q.push(s);
    }
    if(q.size()<=1){
        return 0;
    }
    answer=q.top();
    q.pop();
    return answer*q.top();
}