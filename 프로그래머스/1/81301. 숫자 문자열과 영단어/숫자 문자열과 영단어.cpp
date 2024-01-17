#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> ma = {
    {"zero",0},
    {"one",1},
    {"two",2},
    {"three",3},
    {"four",4},
    {"five",5},
    {"six",6},
    {"seven",7},
    {"eight",8},
    {"nine",9}
};

int solution(string s) {
    int answer = 0;
    string r="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            answer=answer*10+(s[i]-'0');
            continue;
        }
        r+=s[i];
        if(ma.find(r)!=ma.end()){
            answer=answer*10+ma[r];
            r="";
        }
    }
    
    return answer;
}