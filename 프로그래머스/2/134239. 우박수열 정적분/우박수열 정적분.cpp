#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    long long K = k;
    vector<double> answer;
    vector<pair<double,pair<int,long long>>> seq={{0.0,{0,K}}};
    int n=0;
    while(K!=1){
        if(K%2==0){
            K/=2;
        }else{
            K=K*3+1;
        }
        n++;
        double area = seq.back().first+((double)seq.back().second.second+K)/2;
        seq.push_back({area,{n,K}});
    }
    for(int i=0;i<ranges.size();i++){
        int start = ranges[i][0];
        int end = n + ranges[i][1];
        if(start>end){
            answer.push_back(-1);
            continue;
        }
        answer.push_back(seq[end].first-seq[start].first);
    }
    return answer;
}