import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

	static int n, m;
	static int[][] map;
	static int ans = -1;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		String s = br.readLine();
		int n = Integer.parseInt(br.readLine());
		int[] dp = new int[s.length() + 1];
		Map<String, Integer> map = new HashMap<>();
		for (int i = 0; i < n; i++) {
			var st = new StringTokenizer(br.readLine());
			map.put(st.nextToken(), Integer.parseInt(st.nextToken()));
		}

		dp[1] = 1;
		if (map.containsKey(s.substring(0, 1))) {
			dp[1] = map.get(s.substring(0, 1));
		}
		for (int i = 2; i <= s.length(); i++) {
			dp[i] = dp[i - 1] + 1;
			for (var c : map.entrySet()) {
				if (i < c.getKey().length()) {
					continue;
				}
				int len = c.getKey().length();
				if (s.substring(i - len, i).equals(c.getKey())) {
					dp[i] = Math.max(dp[i], dp[i - len] + c.getValue());
				}
			}
		}

		System.out.println(dp[s.length()]);
	}
}