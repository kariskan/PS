#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> st;
    int now=1;
    for(int i=0;i<order.size();i++){
        if(now>order[i]&&!st.empty()&&st.top()>order[i]){
            return i;
        }
        while(now<=order[i]){
            st.push(now++);
        }
        
        st.pop();
        answer++;
    }
    return answer;
}