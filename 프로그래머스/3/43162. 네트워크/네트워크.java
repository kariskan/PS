import java.util.*;

class Solution {
    
    int[][] computers;
    int[] vis = new int[200];
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        this.computers = computers;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
                go(i);
                answer++;
            }
        }
        return answer;
    }
    
    void go(int node) {
        for (int i = 0; i < computers.length; i++) {
            if (vis[i] == 0 && computers[node][i] > 0) {
                vis[i] = 1;
                go(i);
            }
        }
    }
}