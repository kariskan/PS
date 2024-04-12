import java.util.*;

class Solution {
    
    int[] p = new int[100];
    
    public int solution(int n, int[][] costs) {
        int answer = 0;
        Arrays.sort(costs,(o1, o2) -> o1[2]-o2[2]);
        for(int i=0;i<n;i++){
            p[i]=i;
        }
        for(int i=0;i<costs.length;i++){
            if(Find(costs[i][0])!=Find(costs[i][1])){
                Union(costs[i][0],costs[i][1]);
                answer+=costs[i][2];
            }
        }
        return answer;
    }
    
    int Find(int x){
        if(p[x]==x){
            return x;
        }
        return p[x]=Find(p[x]);
    }
    
    void Union(int a,int b){
        a=Find(a);
        b=Find(b);
        p[b]=a;
    }
}