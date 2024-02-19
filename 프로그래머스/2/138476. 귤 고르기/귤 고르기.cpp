#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
map<int,int> ma;
bool compare(pair<int,int>&p1,pair<int,int>&p2){
    return p1.second>p2.second;
}
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(int i=0;i<tangerine.size();i++){
        ma[tangerine[i]]++;
    }
    priority_queue<int> q;
    for(auto&i:ma){
        q.push(i.second);
    }
    int s=0;
    while(!q.empty()){
        if(s+q.top()>=k){
            return answer+1;
        }
        s+=q.top();
        answer++;
        q.pop();
    }
}