#include <string>
#include <vector>
#include <sstream>
using namespace std;
string toJaden(string s){
    if(s[0]>='a'&&s[0]<='z'){
        s[0]=s[0]-'a'+'A';
    }
    for(int i=1;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
        }
    }
    return s;
}
vector<string> parse(string s){
    vector<string> v;
    string temp="";
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            if(!temp.empty()){
                v.push_back(temp);
            }
            v.push_back(" ");
            temp="";
            continue;
        }
        temp+=s[i];
    }
    if(!temp.empty()){
        v.push_back(temp);
    }
    return v;
}
string solution(string s) {
    string answer="";
    vector<string> v=parse(s);
    for(int i=0;i<v.size();i++){
        answer+=toJaden(v[i]);
    }
    return answer;
}