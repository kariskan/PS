#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
stack<int> st;
int solution(vector<int> order) {
    int answer = 0;
    queue<int> q;
    for(int i=1;i<=order.size();i++){
        q.push(i);
    }
    int idx=0;
    for(int i=0;i<order.size();i++){
        if(!q.empty()&&q.front()==order[i]){
            q.pop();
            answer++;
            continue;
        }
        if(!st.empty()&&st.top()==order[i]){
            st.pop();
            answer++;
            continue;
        }
        if((q.empty()||(!q.empty()&&order[i]<q.front()))&&(st.empty()||(!st.empty()&&order[i]!=st.top()))){
            break;
        }
        while(!q.empty()&&q.front()<order[i]){
            st.push(q.front());
            q.pop();
        }
        q.pop();
        answer++;
    }
    return answer;
}