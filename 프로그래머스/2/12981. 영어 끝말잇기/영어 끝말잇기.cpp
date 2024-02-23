#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> se;
    char last=words[0][0];
    for(int i=0;i<words.size();i++){
        if(words[i][0]!=last||words[i].length()<2||se.find(words[i])!=se.end()){
            return {i%n+1,i/n+1};
        }
        se.insert(words[i]);
        last=words[i].back();
    }
    return {0,0};
}