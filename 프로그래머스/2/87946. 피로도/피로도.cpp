#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> seq;
    for(int i=0;i<dungeons.size();i++){
        seq.push_back(i);
    }
    do{
        int K = k, c = 0;
        for(int i=0;i<seq.size();i++){
            if(K>=dungeons[seq[i]][0]){
                K-=dungeons[seq[i]][1];
                c++;
            }
        }
        answer=max(answer, c);
        printf("\n");
    }while(next_permutation(seq.begin(),seq.end()));
    return answer;
}