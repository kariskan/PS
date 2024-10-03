import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[] pre, in;
	static int n;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		// 3 6 5 4 8 7 1 2
		// 5 6 8 4 3 1 2 7
		// 5 8 4 6 2 1 7 3
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			n = Integer.parseInt(br.readLine());
			var st = new StringTokenizer(br.readLine());
			pre = new int[n];
			in = new int[n];
			for (int i = 0; i < n; i++) {
				pre[i] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				in[i] = Integer.parseInt(st.nextToken());
			}
			go(0, 0, n - 1);
			sb.append('\n');
		}
		System.out.println(sb);
	}

	/**
	 * 3 6 5 4 8 7 1 2
	 * 5 6 8 4 3 1 2 7
	 *
	 * 5 8 4 6 2 1 7 3
	 */

	static void go(int now, int l, int r) {
		for (int i = l; i <= r; i++) {
			if (pre[now] == in[i]) {
				go(now + 1, l, i - 1);
				go(now + 1 + i - l, i + 1, r);
				sb.append(pre[now]).append(" ");
				break;
			}
		}
	}
}