#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> st;
    
    for(int i:ingredient){
        st.push(i);
        if(st.size()>=4){
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            int third = st.top();
            st.pop();
            int fourth = st.top();
            st.pop();
            if(first==1&&second==3&&third==2&&fourth==1){
                answer++;
                continue;
            }
            st.push(fourth);
            st.push(third);
            st.push(second);
            st.push(first);
        }
    }
    
    return answer;
}