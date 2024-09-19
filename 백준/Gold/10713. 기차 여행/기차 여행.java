import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n, m;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		int[] path = new int[m + 1];
		long[][] cost = new long[n + 1][3];
		long[] sum = new long[n + 1];
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= m; i++) {
			path[i] = Integer.parseInt(st.nextToken());
			if (i > 1) {
				int min = Math.min(path[i - 1], path[i]);
				int max = Math.max(path[i - 1], path[i]);
				sum[min]++;
				sum[max]--;
			}
		}
		for (int i = 1; i <= n; i++) {
			sum[i] += sum[i - 1];
		}
		for (int i = 1; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			cost[i][0] = Long.parseLong(st.nextToken());
			cost[i][1] = Long.parseLong(st.nextToken());
			cost[i][2] = Long.parseLong(st.nextToken());
		}
		long ans = 0;
		for (int i = 1; i <= n; i++) {
			if (sum[i] == 0) {
				continue;
			}
			ans += Math.min(cost[i][0] * sum[i], cost[i][2] + cost[i][1] * sum[i]);
		}
		System.out.println(ans);
	}
}