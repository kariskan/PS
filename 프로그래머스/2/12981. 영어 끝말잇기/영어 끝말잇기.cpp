#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> se;
    int cnt=1;
    for(int i=0;i<words.size();i++){
        if(words[i].length()<2||(i>0&&words[i-1][words[i-1].length()-1]!=words[i][0])
          ||se.find(words[i])!=se.end()){
            return {cnt,(i+n)/n};
        }
        cnt++;
        if(cnt==n+1){
            cnt=1;
        }
        se.insert(words[i]);
    }
    return {0,0};
}