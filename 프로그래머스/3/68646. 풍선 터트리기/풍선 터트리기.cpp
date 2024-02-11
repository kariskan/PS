#include <string>
#include <vector>

using namespace std;
int lmin[1000000],rmin[1000000];
int solution(vector<int> a) {
    int answer = min((int)a.size(),2);
    lmin[0]=a[0];
    rmin[a.size()-1]=a[a.size()-1];
    for(int i=1;i<a.size();i++){
        lmin[i]=min(lmin[i-1],a[i]);
        rmin[a.size()-i-1]=min(rmin[a.size()-i],a[a.size()-i-1]);
    }
    for(int i=1;i<a.size()-1;i++){
        if(lmin[i]<a[i]&&rmin[i]<a[i]){
            continue;
        }
        answer++;
    }

    return answer;
}