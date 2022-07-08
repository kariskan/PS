#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int now = 1;
    for(int i=0;i<stations.size();i++){
        int right = stations[i] - w - 1;
        answer += (right - now + 1 + w * 2) / (w * 2 + 1);
        now = stations[i] + w + 1;
    }
    answer += (n - now + 1 + w * 2) / (w * 2 + 1);

    return answer;
}