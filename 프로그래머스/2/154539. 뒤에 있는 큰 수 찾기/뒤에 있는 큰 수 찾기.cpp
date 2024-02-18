#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> st;
    answer.push_back(-1);
    st.push(numbers[numbers.size()-1]);
    for(int i=numbers.size()-2;i>=0;i--){
        while(!st.empty()&&st.top()<=numbers[i]){
            st.pop();
        }
        if(st.empty()){
            answer.push_back(-1);
        }else{
            answer.push_back(st.top());
        }
        st.push(numbers[i]);
    }
    reverse(answer.begin(),answer.end());
    return answer;
}