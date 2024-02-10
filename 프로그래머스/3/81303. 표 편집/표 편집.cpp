#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<int> st;
pair<int,int> pos[1000002];
string solution(int n, int k, vector<string> cmd) {
    string answer(n,'O');
    for(int i=0;i<=n-1;i++){
        pos[i]={i-1,i+1};
    }
    pos[n-1].second=-1;
    for(string c:cmd){
        if(c[0]=='U'){
            int t=stoi(c.substr(2));
            while(t-->0){
                k=pos[k].first;
            }
        }else if(c[0]=='D'){
            int t=stoi(c.substr(2));
            while(t-->0){
                k=pos[k].second;
            }
        }else if(c=="C"){
            st.push(k);
            if(pos[k].first!=-1){
                pos[pos[k].first].second=pos[k].second;
            }
            if(pos[k].second!=-1){
                pos[pos[k].second].first=pos[k].first;
            }
            answer[k]='X';
            if(pos[k].second!=-1){
                k=pos[k].second;
            }else{
                k=pos[k].first;
            }
        }else{
            int t=st.top();
            st.pop();
            if(pos[t].first!=-1){
                pos[pos[t].first].second=t;
            }
            if(pos[t].second!=-1){
                pos[pos[t].second].first=t;
            }
            answer[t]='O';
        }
    }
    return answer;
}
