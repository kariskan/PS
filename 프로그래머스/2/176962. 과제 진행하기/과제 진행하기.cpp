#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
bool compare(vector<string>&v1,vector<string>&v2){
    return v1[1]<v2[1];
}
int time(string s){
    return stoi(s.substr(0,2))*60+stoi(s.substr(3));
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(),plans.end(),compare);
    stack<pair<string,int>> st;
    
    for(int i=0;i<plans.size();i++){
        if(i==plans.size()-1){
            answer.push_back(plans[i][0]);
            break;
        }
        int start=time(plans[i][1]);
        int end=start+stoi(plans[i][2]);
        int next=time(plans[i+1][1]);
        
        if(end<=next){
            answer.push_back(plans[i][0]);
            for(int j=0;j<next-end;j++){
                if(st.empty()){
                    break;
                }
                st.top().second--;
                if(st.top().second==0){
                    answer.push_back(st.top().first);
                    st.pop();
                }
            }
        }else{
            st.push({plans[i][0],end-next});
        }
    }
    while(!st.empty()){
        answer.push_back(st.top().first);
        st.pop();
    }
    
    return answer;
}