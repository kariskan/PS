import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static String s;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		while (true) {
			var st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = (int) (Double.parseDouble(st.nextToken()) * 100 + 0.5);
			if (n == 0 && m == 0) {
				break;
			}
			int[] c = new int[n];
			int[] p = new int[n];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				int cc = Integer.parseInt(st.nextToken());
				int pp = (int) (Double.parseDouble(st.nextToken()) * 100 + 0.5);
				c[i] = cc;
				p[i] = pp;
			}
			int[] dp = new int[10001];
			int ans = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 1; j <= m; j++) {
					if (j >= p[i]) {
						dp[j] = Math.max(dp[j], dp[j - p[i]] + c[i]);
					}
					ans = Math.max(ans, dp[j]);
				}
			}
			System.out.println(ans);
		}
	}
}