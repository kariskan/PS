#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string toBinary(long long n){
    string res="";
    while(n){
        res+=(n%2+'0');
        n/=2;
    }
    for(long long i=2;;i*=2){
        if(res.length()<=i-1){
            int len=res.length();
            for(int j=0;j<i-1-len;j++){
                res+='0';
            }
            break;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
vector<int> answer;
bool flag;
bool isValid(string s,int left, int right){
    if(s[(left+right)/2]=='1'){
        return true;
    }
    for(int i=left;i<=right;i++){
        if(s[i]=='1'){
            return false;
        }
    }
    return true;
}
void go(string s,int left,int right){
    if(left>=right){
        return;
    }
    int mid=(left+right)/2;
    if(!isValid(s,left,right)){
        flag=false;
        return;
    }
    go(s,left,mid-1);
    go(s,mid+1,right);
}

vector<int> solution(vector<long long> numbers) {
    for(long long number:numbers){
        flag=true;
        string binary=toBinary(number);
        
        go(binary,0,binary.length()-1);
        answer.push_back(flag);
    }
    return answer;
}