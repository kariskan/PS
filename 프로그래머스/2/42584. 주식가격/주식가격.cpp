#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int,int>> st;
    for(int i=0;i<prices.size();i++){
        while(!st.empty()&&st.top().first>prices[i]){
            answer[st.top().second]=i-st.top().second;
            st.pop();
        }
        st.push({prices[i],i});
    }
    while(!st.empty()){
        answer[st.top().second]=prices.size()-st.top().second-1;
        st.pop();
    }
    return answer;
}