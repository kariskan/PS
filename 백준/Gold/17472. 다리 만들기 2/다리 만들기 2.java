import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	//	static int n, m;
//	static int[][] map;
//	static int ans = -1;
	static int[] p;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

//		var st = new StringTokenizer(br.readLine());
//		n = Integer.parseInt(st.nextToken());
//		m = Integer.parseInt(st.nextToken());
//
//		map = new int[n + 1][n + 1];
//
//		for (int i = 0; i < m; i++) {
//			st = new StringTokenizer(br.readLine());
//			int a = Integer.parseInt(st.nextToken());
//			int b = Integer.parseInt(st.nextToken());
//			int c = Integer.parseInt(st.nextToken());
//			map[a][b] = c;
//		}
//		for (int k = 1; k <= n; k++) {
//			for (int i = 1; i <= n; i++) {
//				for (int j = 1; j <= n; j++) {
//					if (i == j) {
//						continue;
//					}
//					if (map[i][k] > 0 && map[k][j] > 0) {
//						if (map[i][j] == 0 || map[i][j] > map[i][k] + map[k][j]) {
//							map[i][j] = map[i][k] + map[k][j];
//						}
//					}
//				}
//			}
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				System.out.print(map[i][j] + " ");
//			}
//			System.out.println();
//		}
//		System.out.println();
//		for (int k = 1; k <= n; k++) {
//			for (int i = 1; i <= n; i++) {
//				for (int j = 1; j <= n; j++) {
//					if (i == j) {
//						continue;
//					}
//					if (map[i][k] > 0 && map[k][j] > 0) {
//						if (map[i][j] == 0 || map[i][j] > map[i][k] + map[k][j]) {
//							map[i][j] = map[i][k] + map[k][j];
//						}
//					}
//				}
//			}
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				System.out.print(map[i][j] + " ");
//			}
//			System.out.println();
//		}
//		System.out.println(ans);
		int n, m;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[][] map = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int cnt = 1;
		int[][] vis = new int[n][m];
		int[] dx = {0, 0, 1, -1};
		int[] dy = {1, -1, 0, 0};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && vis[i][j] == 0) {
					vis[i][j] = cnt;
					Queue<int[]> q = new ArrayDeque<>();
					q.offer(new int[]{i, j});
					while (!q.isEmpty()) {
						var now = q.poll();
						for (int k = 0; k < 4; k++) {
							int nx = now[0] + dx[k];
							int ny = now[1] + dy[k];
							if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && map[nx][ny] == 1) {
								vis[nx][ny] = vis[now[0]][now[1]];
								q.offer(new int[]{nx, ny});
							}
						}
					}
					cnt++;
				}
			}
		}
		List<int[]> v = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int i1 = 0; i1 < n; i1++) {
					for (int j1 = 0; j1 < m; j1++) {
						if (vis[i][j] == 0 || vis[i1][j1] == 0 || vis[i][j] == vis[i1][j1]) {
							continue;
						}
						boolean flag = false;
						if (i == i1 && Math.abs(j - j1) >= 3) {
							for (int k = Math.min(j, j1) + 1; k < Math.max(j, j1); k++) {
								if (map[i1][k] != 0) {
									flag = true;
									break;
								}
							}
							if (flag) {
								continue;
							}
							v.add(new int[]{vis[i][j], vis[i1][j1], Math.abs(j - j1) - 1});
						} else if (j == j1 && Math.abs(i - i1) >= 3) {
							for (int k = Math.min(i, i1) + 1; k < Math.max(i, i1); k++) {
								if (map[k][j1] != 0) {
									flag = true;
									break;
								}
							}
							if (flag) {
								continue;
							}
							v.add(new int[]{vis[i][j], vis[i1][j1], Math.abs(i - i1) - 1});
						}
					}
				}
			}
		}
		v.sort(Comparator.comparing(a -> a[2]));
		p = new int[cnt];
		for (int i = 0; i < cnt; i++) {
			p[i] = i;
		}
		int ans = 0;
		for (int[] c : v) {
			int pa = find(c[0]);
			int pb = find(c[1]);
			if (pa != pb) {
				p[pb] = pa;
				ans += c[2];
			}
		}

		for (int i = 1; i < cnt; i++) {
			if (find(1) != find(i)) {
				ans = -1;
			}
		}
		System.out.println(ans);
	}

	static int find(int x) {
		if (x == p[x]) {
			return x;
		}
		return p[x] = find(p[x]);
	}
}