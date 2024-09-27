import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());
		var sb = new StringBuilder();
		while (t-- > 0) {
			var st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(br.readLine());
			int[] house = new int[n];
			int money = 0;
			int ans = 0;
			for (int i = 0; i < n; i++) {
				house[i] = Integer.parseInt(st.nextToken());
				if (i < m) {
					money += house[i];
				}
			}
			if (money < k) {
				ans++;
			}
			if (n != m) {
				for (int i = 1; i < n; i++) {
					money -= house[i - 1];
					money += house[(i + m - 1) % n];
					if (money < k) {
						ans++;
					}
				}
			}
			sb.append(ans).append("\n");
		}
		System.out.println(sb);
	}
}