import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int[] dx = {0, 0, 1, -1};
		int[] dy = {1, -1, 0, 0};
		while (t-- > 0) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());

			for (int i = 0; i < n; i++) {
				if ((i + 1) % x != 0) {
					continue;
				}
				int[] temp = new int[m];
				for (int j = 0; j < m; j++) {
					if (d == 0) {
						temp[(j + k) % m] = a[i][j];
					} else {
						temp[(j - k + m) % m] = a[i][j];
					}
				}
				System.arraycopy(temp, 0, a[i], 0, m);
			}

			Queue<int[]> q = new ArrayDeque<>();
			boolean[][] vis = new boolean[n][m];
			boolean flag = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (a[i][j] == 0 || vis[i][j]) {
						continue;
					}

					q.offer(new int[]{i, j});
					vis[i][j] = true;

					List<int[]> v = new ArrayList<>();
					while (!q.isEmpty()) {
						var c = q.poll();
						v.add(c);

						for (int l = 0; l < 4; l++) {
							int nx = c[0] + dx[l];
							int ny = c[1] + dy[l];
							if (ny == -1) {
								ny = m - 1;
							} else if (ny == m) {
								ny = 0;
							}
							if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
								!vis[nx][ny] && a[nx][ny] == a[c[0]][c[1]]) {
								vis[nx][ny] = true;
								q.offer(new int[]{nx, ny});
							}
						}
					}
					if (v.size() > 1) {
						flag = true;
						for (var c : v) {
							a[c[0]][c[1]] = 0;
						}
					}
				}
			}
			if (!flag) {
				int sum = 0;
				int cnt = 0;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (a[i][j] == 0) {
							continue;
						}
						sum += a[i][j];
						cnt++;
					}
				}
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (a[i][j] == 0) {
							continue;
						}
						if (a[i][j] * cnt > sum) {
							a[i][j]--;
						} else if (a[i][j] * cnt < sum) {
							a[i][j]++;
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans += a[i][j];
			}
		}
		System.out.println(ans);
	}
}