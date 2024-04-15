import java.util.*;

class Solution {
    public long solution(int[] sequence) {
        List<Long> v = new ArrayList<>();
        long answer = 0, mi = 0, ma = 0;
        for (int i = 0; i < sequence.length; i++) {
            if (i % 2 == 1) {
                sequence[i] *= -1;
            }
            v.add((long) sequence[i]);
            if (i > 0) {
                v.set(i, v.get(i) + v.get(i - 1));
            }
        }
        for (int i = 0; i < v.size(); i++) {
            answer = Math.max(answer, Math.max(Math.abs(v.get(i) - mi), Math.abs(v.get(i) - ma)));
            mi = Math.min(mi, v.get(i));
            ma = Math.max(ma, v.get(i));
        }
        return answer;
    }
}