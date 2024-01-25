#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
string solution(string number, int k) {
    string answer = "";
    stack<char> st;
    for(int i=0;i<number.size();i++){
        while(!st.empty()&&k&&st.top()<number[i]){
            st.pop();
            k--;
        }
        st.push(number[i]);
    }
    while(!st.empty()){
        answer+=st.top();
        st.pop();
    }
    reverse(answer.begin(),answer.end());
    return answer.substr(0, number.length()-k);
}