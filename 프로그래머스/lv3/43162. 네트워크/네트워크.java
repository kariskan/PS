import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

class Solution {

	public int solution(int n, int[][] computers) {
		int answer = 0;

		List<List<Integer>> v = new ArrayList<>(n);

		for (int i = 0; i < n; i++) {
			v.add(new ArrayList<>());
		}

		for (int i = 0; i < computers.length; i++) {
			for (int j = 0; j < computers[i].length; j++) {
				if (i == j) {
					continue;
				}
				if (computers[i][j] == 1) {
					v.get(i).add(j);
					v.get(j).add(i);
				}
			}
		}

		Queue<Integer> q = new ArrayDeque<>();
		int[] visit = new int[n];

		for (int i = 0; i < n; i++) {
			if (visit[i] == 0) {
				answer++;
				visit[i] = 1;
				q.offer(i);

				while (!q.isEmpty()) {
					int node = q.poll();

					for (int j = 0; j < v.get(node).size(); j++) {
						int next = v.get(node).get(j);
						if (visit[next] == 0) {
							q.offer(next);
							visit[next] = 1;
						}
					}
				}
			}
		}

		return answer;
	}
}