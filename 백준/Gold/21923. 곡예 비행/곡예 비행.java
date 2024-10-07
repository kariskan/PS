import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] map = new int[n + 2][m + 2];
		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int[][] up = new int[n + 2][m + 2];
		int[][] down = new int[n + 2][m + 2];
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				up[i][j] = down[i][j] = Integer.MIN_VALUE;
			}
		}

		up[n][1] = map[n][1];
		for (int j = 1; j <= m; j++) {
			for (int i = n; i >= 1; i--) {
				if (i == n && j == 1) {
					continue;
				}
				up[i][j] = Math.max(up[i + 1][j], up[i][j - 1]) + map[i][j];
			}
		}
		down[n][m] = map[n][m];
		for (int i = n; i >= 1; i--) {
			for (int j = m; j >= 1; j--) {
				if (i == n && j == m) {
					continue;
				}
				down[i][j] = Math.max(down[i + 1][j], down[i][j + 1]) + map[i][j];
			}
		}

		int ans = Integer.MIN_VALUE;
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				System.out.print(up[i][j] + " ");
//			}
//			System.out.println();
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				System.out.print(down[i][j] + " ");
//			}
//			System.out.println();
//		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ans = Math.max(ans, up[i][j] + down[i][j]);
			}
		}
		System.out.println(ans);
	}
}