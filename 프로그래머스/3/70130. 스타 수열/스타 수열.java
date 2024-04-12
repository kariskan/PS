import java.util.*;

class Solution {
	public int solution(int[] a) {
		int answer = 0;
		Map<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < a.length; i++) {
			map.put(a[i], map.getOrDefault(a[i], 0) + 1);
		}
		Queue<Pair> pq = new PriorityQueue<>();
		for (var v: map.entrySet()) {
			pq.add(new Pair(v.getValue(), v.getKey()));
		}
		while (!pq.isEmpty()) {
			if (pq.peek().first * 2 < answer) {
				break;
			}
			int k = pq.peek().second;
			pq.poll();

			int cnt = 0;
			for (int i = 0; i < a.length - 1; i++) {
				if ((a[i] == k && a[i + 1] != k) || (a[i] != k && a[i + 1] == k)) {
					cnt += 2;
					i++;
				}
			}
			answer = Math.max(answer, cnt);
		}

		return answer;
	}

	class Pair implements Comparable<Pair> {
		public int first;
		public int second;

		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}

		@Override
		public int compareTo(Pair p) {
			if (this.first > p.first || (this.first == p.first && this.second > p.second)) {
				return -1;
			} else {
				return 1;
			}
		}
	}
}