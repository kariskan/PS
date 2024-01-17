#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int sum[502];
vector<pair<int, double>> v;

bool compare(pair<int, double>& p1, pair<int, double>& p2) {
    if (p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second>p2.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int s=0;
    for(int i=0;i<stages.size();i++){
        sum[stages[i]]++;
    }
    for(int i=1;i<=N;i++){
        double rate;
        if(s==stages.size()){
            rate = 0;
        }else {
            rate = (double)sum[i]/(stages.size()-s) * 1.0;
        }
        v.push_back({i,rate});
        s+=sum[i];
    }
    sort(v.begin(),v.end(), compare);
    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].first);
    }
    return answer;
}