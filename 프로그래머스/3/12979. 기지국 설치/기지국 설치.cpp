#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w){
    int answer = 0;
    
    int pre=0;
    for(int i=0;i<stations.size();i++){
        int now=stations[i]-w-1;
        answer+=max(0,(now-pre+w*2)/(w*2+1));
        pre=stations[i]+w;
    }
    answer+=max(0,(n-pre+w*2)/(w*2+1));
    
    return answer;
}