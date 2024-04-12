import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        Queue<Integer> pq = new PriorityQueue<>((n1, n2) -> n1 - n2);
        for (int i = 0; i < works.length; i++) {
            pq.add(works[i]);
        }
        while (!pq.isEmpty() && n > 0) {
            int a = pq.poll();
            if (a > 1) {
                pq.add(a - 1);
            }
            n--;
        }
        while (!pq.isEmpty()) {
            long a = pq.poll();
            answer += a * a;
        }
        return answer;
    }
}