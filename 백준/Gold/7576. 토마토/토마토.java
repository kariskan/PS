import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		int n, m;
		int[][] map = new int[1000][1000];
		int[][] vis = new int[1000][1000];
		var st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());

		Queue<int[]> q = new ArrayDeque<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 1) {
					q.offer(new int[] {i, j});
					vis[i][j] = 1;
				}
			}
		}

		int[] dx = {0, 0, 1, -1};
		int[] dy = {1, -1, 0, 0};
		int ans = 0;
		while (!q.isEmpty()) {
			int[] now = q.poll();

			ans = Math.max(ans, vis[now[0]][now[1]]);
			for (int i = 0; i < 4; i++) {
				int nx = now[0] + dx[i];
				int ny = now[1] + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != -1 && vis[nx][ny] == 0) {
					vis[nx][ny] = vis[now[0]][now[1]] + 1;
					q.offer(new int[] {nx, ny});
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != -1 && vis[i][j] == 0) {
					System.out.println(-1);
					return;
				}
			}
		}
		System.out.println(ans - 1);
	}
}