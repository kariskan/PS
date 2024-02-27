#include <string>
#include <vector>
#include <queue>
using namespace std;
//                2          10            [7,4,5,6]
int solution(int length, int weight, vector<int> truck) {
    int answer = 0;
    int nowWeight=0,idx=0;
    queue<pair<int,int>> q;
    while(!q.empty()||idx<truck.size()){
        if(!q.empty()&&q.front().first+length<=answer){
            nowWeight-=truck[q.front().second];
            q.pop();
        }
        if(idx<truck.size()&&nowWeight+truck[idx]<=weight&&q.size()<length){
            nowWeight+=truck[idx];
            q.push({answer,idx++});
        }
        answer++;
    }
    return answer;
}