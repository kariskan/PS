import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		String s = br.readLine();

		Map<Character, Integer> map = new HashMap<>();
		int left = 0, right = -1, ans = 0;
		while (right < s.length() - 1) {
			right++;
			char c = s.charAt(right);
			map.put(c, map.getOrDefault(c, 0) + 1);
			while (map.size() > n) {
				char l = s.charAt(left);
				map.put(l, map.get(l) - 1);
				if (map.get(l) == 0) {
					map.remove(l);
				}
				left++;
			}
			ans = Math.max(ans, right - left + 1);
		}

		System.out.println(ans);
	}
}