import java.util.*;

class Solution {
    
    int[][] beginning;
    int[][] target;
    int n, m;
    int answer = -1;
    
    public int solution(int[][] beginning, int[][] target) {
        this.beginning = beginning;
        this.target = target;
        n = beginning.length;
        m = beginning[0].length;
        go(new ArrayList<>(), 0);
        return answer;
    }
    
    int[][] flap(List<Integer> v) {
        int[][] res = new int[beginning.length][beginning[0].length];
        for(int i=0;i<beginning.length;i++){
            for(int j=0;j<beginning[i].length;j++){
                res[i][j]=beginning[i][j];
            }
        }
        
        for (int i = 0; i < v.size(); i++) {
            int idx = v.get(i);
            for (int j = 0; j < m; j++) {
                res[idx][j] = 1 - res[idx][j];
            }
        }
        return res;
    }
    
    void go(List<Integer> now, int idx) {
        if (idx == n) {
            int[][] res = flap(now);
            int totalCnt = now.size();
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (res[i][j] != target[i][j]) {
                        cnt++;
                    }
                }
                if (cnt > 0 && cnt < n) {
                    return;
                }
                if (cnt == 0) {
                    continue;
                }
                totalCnt++;
            }
            if (answer == -1 || answer > totalCnt) {
                answer = totalCnt;
            }
            return;
        }
        
        go(now, idx + 1);
        now.add(idx);
        go(now, idx + 1);
        now.remove(now.size() - 1);
    }
}