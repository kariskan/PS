#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    for(int i=0;i<enemy.size();i++){
        pq.push(enemy[i]);
        if(n<enemy[i]){
            while(!pq.empty()&&k&&n<enemy[i]){
                k--;
                n+=pq.top();
                pq.pop();
            }
            if(n<enemy[i]){
                return i;
            }
        }
        n-=enemy[i];
    }
    return enemy.size();
}