#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

char op[3]={'+','-','*'};

long long solution(string expression) {
    long long answer = 0;
    vector<int> seq={0,1,2};
    do{
        vector<string> v;
        string s="";
        for(int i=0;i<expression.length();i++){
            if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'){
                v.push_back(s);
                string temp="";
                temp+=expression[i];
                v.push_back(temp);
                s="";
                continue;
            }
            s+=expression[i];
        }
        v.push_back(s);
        for(int i=0;i<3;i++){
            for(int j=1;j<v.size();j+=2){
                if(seq[i]==0&&v[j][0]=='+'){
                    long long res = stoll(v[j-1])+stoll(v[j+1]);
                    v[j+1]=to_string(res);
                    v.erase(v.begin()+j-1);
                    v.erase(v.begin()+j-1);
                    j-=2;
                }else if(seq[i]==1&&v[j][0]=='-'){
                    long long res = stoll(v[j-1])-stoll(v[j+1]);
                    v[j+1]=to_string(res);
                    v.erase(v.begin()+j-1);
                    v.erase(v.begin()+j-1);
                    j-=2;
                }else if(seq[i]==2&&v[j][0]=='*'){
                    long long res = stoll(v[j-1])*stoll(v[j+1]);
                    v[j+1]=to_string(res);
                    v.erase(v.begin()+j-1);
                    v.erase(v.begin()+j-1);
                    j-=2;
                }
            }
        }
        answer=max(answer,abs(stoll(v[0])));
    }while(next_permutation(seq.begin(),seq.end()));
    return answer;
}