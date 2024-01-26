#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
map<string,string> ma={
    {"C","0"},
    {"C#","1"},
    {"D","2"},
    {"D#","3"},
    {"E","4"},
    {"F","5"},
    {"F#","6"},
    {"G","7"},
    {"G#","8"},
    {"A","9"},
    {"A#","A"},
    {"B","B"},
};
vector<string> parse(string music){
    stringstream ss(music);
    vector<string> v;
    string temp;
    while(getline(ss,temp,',')){
        v.push_back(temp);
    }
    return v;
}
string parse2(string music){
    string res="";
    for(int i=0;i<music.length();i++){
        if(i<music.length()-1&&music[i+1]=='#'){
            res+=ma[music.substr(i,2)];
            i++;
        }else{
            res+=ma[music.substr(i,1)];
        }
    }
    return res;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int maxLen=0;
    m=parse2(m);
    for(string music:musicinfos){
        vector<string> v=parse(music);
        int start=stoi(v[0].substr(0,2))*60+stoi(v[0].substr(3));
        int end=stoi(v[1].substr(0,2))*60+stoi(v[1].substr(3));
        string title=v[2];
        string info=parse2(v[3]);
        
        string s="";
        
        for(int i=0;i<(end-start+1)/info.length();i++){
            s+=info;
        }
        s+=info.substr(0,(end-start+1)%info.length());
        // printf("s: %s, m: %s\n", s.c_str(), parse2(m).c_str());
        for(int i=0;i<=(int)s.length()-(int)m.length();i++){
            // printf("%s\n", s.substr(i,(int)m.length()).c_str());
            if(s.substr(i,(int)m.length())==m){
                if(maxLen<end-start+1){
                    maxLen=end-start+1;
                    answer=title;
                    break;
                }
            }
        }
    }
    return answer==""?"(None)":answer;
}