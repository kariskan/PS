#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int vis[100000];
int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<a.size();i++){
        int left=0,right=(int)b.size()-1;
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            
            if(vis[mid]||b[mid]<=a[i]){
                left=mid+1;
            }else{
                right=mid-1;
                ans=mid;
            }
        }
        if(ans!=-1){
            vis[ans]=1;
            answer++;
        }
    }
    return answer;
}