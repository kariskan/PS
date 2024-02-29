#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(),tangerine.end());
    map<int,int> ma;
    for(int t:tangerine){
        ma[t]++;
    }
    priority_queue<int> q;
    for(auto&i:ma){
        q.push(i.second);
    }
    int cnt=0;
    while(cnt<k){
        cnt+=q.top();
        q.pop();
        answer++;
    }
    return answer;
}