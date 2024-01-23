#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string parse(int n){
    string res="";
    while(n){
        res+=(n%2+'0');
        n/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}

vector<int> solution(string s) {
    int term=0,cnt=0;
    while(s!="1"){
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                s.erase(s.begin()+i);
                i--;
                cnt++;
            }
        }
        s=parse(s.length());
        term++;
    }
    return {term,cnt};
}