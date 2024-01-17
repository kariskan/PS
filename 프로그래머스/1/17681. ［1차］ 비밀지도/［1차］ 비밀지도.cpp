#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int map[16][16],n;

string parse(int k){
    string res="";
    while(k){
        res+=to_string(k%2);
        k/=2;
    }
    int len = res.length();
    for(int i=0;i<n-len;i++){
        res+="0";
    }
    reverse(res.begin(),res.end());
    return res;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    ::n=n;
    for(int i=0;i<arr1.size();i++){
        string binary=parse(arr1[i]);
        for(int j=0;j<n;j++){
            if(binary[j]=='1'){
                map[i][j]=1;
            }
        }
    }
    for(int i=0;i<arr2.size();i++){
        string binary=parse(arr2[i]);
        for(int j=0;j<n;j++){
            if(binary[j]=='1'){
                map[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        string s="";
        for(int j=0;j<n;j++){
            if(map[i][j]){
                s+="#";
            }else{
                s+=" ";
            }
        }
        answer.push_back(s);
    }
    return answer;
}