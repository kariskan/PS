#include <string>
#include <vector>
#include <sstream>
using namespace std;

int time(string s){
    return stoi(s.substr(0,2))*60+stoi(s.substr(3));
}
vector<string> parse(string s){
    stringstream ss(s);
    vector<string> v;
    string temp;
    while(getline(ss,temp,',')){
        v.push_back(temp);
    }
    return v;
}
string parse2(string s){
    string res="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='#'){
            res.pop_back();
            res+=s[i-1]-'A'+'H';
        }else{
            res+=s[i];
        }
    }
    return res;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int maxPlayTime=0;
    m=parse2(m);
    for(string music:musicinfos){
        vector<string> v=parse(music);
        int start=time(v[0]);
        int end=time(v[1]);
        string title=v[2];
        string info=parse2(v[3]);
        
        string total="";
        for(int i=0;i<(end-start)/info.length();i++){
            total+=info;
        }
        if(total.length()<end-start){
            total+=info.substr(0,end-start-total.length());
        }
        for(int i=0;i<=(int)total.length()-(int)m.length();i++){
            if(total.substr(i,m.length())==m){
                if(maxPlayTime<end-start){
                    maxPlayTime=end-start;
                    answer=title;
                }
            }
        }
    }
    
    if(answer==""){
        return "(None)";
    }
    return answer;
}