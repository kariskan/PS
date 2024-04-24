class Solution {
    
    int[] cnt = new int[5000001];
    int[] ans = new int[5000001];
    
    public int[] solution(int e, int[] starts) {
        for (int i = 1; i <= e; i++) {
            for (int j = i; j <= e; j += i) {
                cnt[j]++;
            }
        }
        
        int max = 0, idx = e;
        for (int i = e; i >= 1; i--) {
            if (max <= cnt[i]) {
                max = cnt[i];
                idx = i;
            }
            ans[i] = idx;
        }
        
        int[] answer = new int[starts.length];
        for (int i = 0; i < starts.length; i++) {
            answer[i] = ans[starts[i]];
        }
        return answer;
    }
}