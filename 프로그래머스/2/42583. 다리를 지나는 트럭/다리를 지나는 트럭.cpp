#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int len, int weight, vector<int> weights) {
    int answer = 0, nowWeight=0,idx=0;
    queue<pair<int,int>> q;
    for(int t=1;;t++){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            q.front().second++;
            pair<int,int> front=q.front();
            q.pop();
            if(front.second==len){
                nowWeight-=weights[front.first];
                continue;
            }
            q.push(front);
        }
        if(idx<weights.size()&&q.size()<len&&nowWeight+weights[idx]<=weight){
            nowWeight+=weights[idx];
            q.push({idx++,0});
        }
        if(idx>=weights.size()&&q.empty()){
            return t;
        }
    }
    return answer;
}