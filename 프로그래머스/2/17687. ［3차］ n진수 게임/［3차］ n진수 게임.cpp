#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string parse(int n,int m){
    if(n==0){
        return "0";
    }
    string res="";
    while(n){
        if(m<10||n%m<10){
            res+=n%m+'0';
        }else{
            res+=(n%m-10)+'A';
        }
        n/=m;
    }
    reverse(res.begin(),res.end());
    return res;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string s="";
    for(int i=0;;i++){
        s+=parse(i,n);
        if(s.length()>=m*t){
            break;
        }
    }
    printf("%s\n",s.c_str());
    for(int i=0;i<s.length();i++){
        if((i+1)%m==p%m){
            answer+=s[i];
        }
        if(answer.length()==t){
            break;
        }
    }
    return answer;
}