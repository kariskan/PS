import java.util.*;

class Solution {
	public int[] solution(String[] operations) {
		int[] answer = {};

		Map<Integer, Integer> map = new HashMap<>();
		Queue<Integer> maxQ = new PriorityQueue<>((n1, n2) -> n2 - n1);
		Queue<Integer> minQ = new PriorityQueue<>();

		for (String op: operations) {
			char i = op.charAt(0);
			int num = Integer.parseInt(op.substring(2));
			if (i == 'I') {
				minQ.add(num);
				maxQ.add(num);
				map.put(num, map.getOrDefault(num, 0) + 1);
			} else {
				if (num == 1) {
					// ma[maxQ.top()] == 0
					while (!maxQ.isEmpty() && map.getOrDefault(maxQ.peek(), 0) == 0) {
						maxQ.poll();
					}
					if (!maxQ.isEmpty()) {
						// ma[maxQ.top()]--;
						map.put(maxQ.peek(), map.get(maxQ.peek()) - 1);
						maxQ.poll();
					}
				} else {
					while (!minQ.isEmpty() && map.getOrDefault(minQ.peek(), 0) == 0) {
						minQ.poll();
					}
					if (!minQ.isEmpty()) {
						map.put(minQ.peek(), map.get(minQ.peek()) - 1);
						minQ.poll();
					}
				}
			}
		}
		while (!maxQ.isEmpty() && map.getOrDefault(maxQ.peek(), 0) == 0) {
			maxQ.poll();
		}
		while (!minQ.isEmpty() && map.getOrDefault(minQ.peek(), 0) == 0) {
			minQ.poll();
		}
		if (minQ.isEmpty() || maxQ.isEmpty()) {
			return new int[]{0, 0};
		}

		return new int[]{maxQ.peek(), minQ.peek()};
	}
}