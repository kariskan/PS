#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int last=1;
    vector<int> v;
    for(int i=0;i<stations.size();i++){
        v.push_back(stations[i]-w-1-last+1);
        last=stations[i]+w+1;
    }
    if(last<=n){
        v.push_back(n-last+1);
    }
    int left=0,right=n-stations.size();
    int cnt=0,len=1+2*w;
    for(int i=0;i<v.size();i++){
        cnt+=(v[i]+len-1)/len;
    }
    return cnt;
}