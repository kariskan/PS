#include <string>
#include <vector>
#include <queue>
using namespace std;

int pos[1000001];

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int i=numbers.size()-1;i>=0;i--){
        if(i==numbers.size()-1){
            q.push({i,numbers[i]});
            answer[i]=-1;
            continue;
        }
        while(!q.empty()&&q.top().second<=numbers[i]){
            q.pop();
        }
        if(q.empty()){
            answer[i]=-1;
        }else{
            answer[i]=q.top().second;
        }
        q.push({i,numbers[i]});
    }
    
    return answer;
}