#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int getZeroCnt(string s){
    int cnt=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            cnt++;
        }
    }
    return cnt;
}
string toBinary(int a){
    string res="";
    while(a){
        res+=(a%2+'0');
        a/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}
vector<int> solution(string s) {
    int cnt=0,totalZeroCnt=0;
    while(s!="1"){
        int zeroCnt=getZeroCnt(s);
        s=toBinary(s.length()-zeroCnt);
        cnt++;
        totalZeroCnt+=zeroCnt;
    }
    return {cnt,totalZeroCnt};
}