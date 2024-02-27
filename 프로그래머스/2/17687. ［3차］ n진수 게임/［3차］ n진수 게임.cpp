#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string toBinary(int num, int n){
    if(num==0){
        return "0";
    }
    string res="";
    while(num){
        if(num%n>=10){
            res+=(num%n-10+'A');
        }else{
            res+=(num%n+'0');
        }
        num/=n;
    }
    reverse(res.begin(),res.end());
    return res;
}

string solution(int n, int t, int m, int p) {
    string answer="",s="";
    int num=0;
    while(s.length()<=m*t){
        s+=toBinary(num++,n);
    }
    for(int i=0;i<t;i++){
        answer+=(s[p-1]);
        p+=m;
    }
    return answer;
}