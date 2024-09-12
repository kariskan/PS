import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int n, m;
	static int ans = Integer.MAX_VALUE;
	static int[][] map;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n + 1][m + 2];

		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int j = 0; j < m; j++) {
			go(0, j, 0, 0);
			go(0, j, 1, 0);
			go(0, j, 2, 0);
		}

		System.out.println(ans);
	}

	static void go(int i, int j, int dir, int sum) {
		if (j == -1 || j == m) {
			return;
		}
		sum += map[i][j];
		if (i == n) {
			ans = Math.min(ans, sum);
			return;
		}

		if (dir == 0) {
			go(i + 1, j, 1, sum);
			go(i + 1, j + 1, 2, sum);
		}
		if (dir == 1) {
			go(i + 1, j - 1, 0, sum);
			go(i + 1, j + 1, 2, sum);
		}
		if (dir == 2) {
			go(i + 1, j - 1, 0, sum);
			go(i + 1, j, 1, sum);
		}
	}
}