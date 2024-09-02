import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static long[] a = new long[20001];
	static long[] dp = new long[20001];

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		int n, m, k;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= n; i++) {
			a[i] = Long.parseLong(br.readLine());
			dp[i] = dp[i - 1] + k;
			long min = a[i];
			long max = a[i];
			for (int j = i - 1; j >= Math.max(i - m + 1, 1); j--) {
				min = Math.min(min, a[j]);
				max = Math.max(max, a[j]);
				dp[i] = Math.min(dp[i], k + (i - j + 1) * (max - min) + dp[j - 1]);
			}
		}
		System.out.println(dp[n]);
	}
}