import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int n, m, k;
	static int[][] map;
	static int[] dx = {0, 0, 1, -1};
	static int[] dy = {1, -1, 0, 0};

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		map = new int[n][m];
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			for (int j = 0; j < m; j++) {
				map[i][j] = s.charAt(j) - '0';
			}
		}

		List<List<int[]>> v = new ArrayList<>();
		for (int i = 0; i < n * m; i++) {
			v.add(new ArrayList<>());
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
						int cost = map[nx][ny] == 1 ? 1 : 0;
						v.get(i * m + j).add(new int[]{nx * m + ny, cost});
					}
				}
			}
		}

		int[][][] vis = new int[n][m][k + 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int c = 0; c <= k; c++) {
					vis[i][j][c] = -1;
				}
			}
		}
		vis[0][0][0] = 1;
		Queue<int[]> q = new ArrayDeque<>();
		q.offer(new int[]{0, 0, 1, 0}); // x, y, cost, wall

		while (!q.isEmpty()) {
			var now = q.poll();

			for (int i = 0; i < 4; i++) {
				int nx = now[0] + dx[i];
				int ny = now[1] + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					int nxCost = now[2] + 1;
					int nxWall = now[3] + (map[nx][ny] == 1 ? 1 : 0);
					if (nxWall > k) {
						continue;
					}
					if (vis[nx][ny][nxWall] == -1) {
						vis[nx][ny][nxWall] = nxCost;
						q.offer(new int[]{nx, ny, nxCost, nxWall});
					}
				}
			}
		}

		int ans = -1;
		for (int i = 0; i <= k; i++) {
			if (vis[n - 1][m - 1][i] == -1) {
				continue;
			}
			if (ans == -1 || ans > vis[n - 1][m - 1][i]) {
				ans = vis[n - 1][m - 1][i];
			}
		}
		System.out.println(ans);
	}
}