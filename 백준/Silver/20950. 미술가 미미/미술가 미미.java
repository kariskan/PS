import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[][] a = new int[30][3];
	static int n;
	static int[] g = new int[3];
	static boolean[] vis = new boolean[30];
	static int ans = Integer.MAX_VALUE;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			var st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 3; j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		var st = new StringTokenizer(br.readLine());
		for (int i = 0; i < 3; i++) {
			g[i] = Integer.parseInt(st.nextToken());
		}

		go(0, 0);
		System.out.println(ans);
	}

	static void go(int idx, int cnt) {
		if (idx == n || cnt == 7) {
			if (cnt < 2) {
				return;
			}
			int[] sum = new int[3];
			for (int i = 0; i < n; i++) {
				if (vis[i]) {
					for (int j = 0; j < 3; j++) {
						sum[j] += a[i][j];
					}
				}
			}
			sum[0] /= cnt;
			sum[1] /= cnt;
			sum[2] /= cnt;
			ans = Math.min(ans, Math.abs(sum[0] - g[0]) + Math.abs(sum[1] - g[1]) + Math.abs(sum[2] - g[2]));
			return;
		}
		go(idx + 1, cnt);
		vis[idx] = true;
		go(idx + 1, cnt + 1);
		vis[idx] = false;
	}
}