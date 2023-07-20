import java.util.*;

class Process {
	int priority;
	int idx;

	public Process(int priority, int i) {
		this.priority = priority;
		this.idx = i;
	}

	public int getPriority() {
		return priority;
	}

	public int getIdx() {
		return idx;
	}
}

class Solution {
	public static int solution(int[] priorities, int location) {
		int answer = 0;

		PriorityQueue<Integer> q = new PriorityQueue<>(Comparator.reverseOrder());
		Queue<Process> list = new ArrayDeque<>();

		for (int i = 0; i < priorities.length; i++) {
			list.add(new Process(priorities[i], i));
			q.offer(priorities[i]);
		}

		while (!list.isEmpty()) {
			while (q.peek() != list.peek().getPriority()) {
				Process p = list.peek();
				list.poll();
				list.offer(p);
			}
			answer++;
			if (list.peek().idx == location) {
				return answer;
			}
			list.poll();
			q.poll();
		}

		return answer;
	}
}