import java.util.*;

class Solution {
	public String solution(String[] participant, String[] completion) {
		String answer = "";

		Map<String, Integer> map = new HashMap<>();

		for (String s : participant) {
			int a = map.getOrDefault(s, 0);
			map.put(s, a + 1);
		}

		for (String s : completion) {
			int a = map.get(s);
			map.put(s, a - 1);
		}

		
		for (var iter : map.entrySet()) {
			if (iter.getValue() != 0) {
				return iter.getKey();
			}
		}

		return answer;
	}
}