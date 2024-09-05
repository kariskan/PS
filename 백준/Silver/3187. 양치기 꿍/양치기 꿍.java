import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static char[][] map = new char[250][250];
	static int[][] visit = new int[250][250];
	static int[] dx = {0, 0, 1, -1};
	static int[] dy = {1, -1, 0, 0};

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n, m;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			for (int j = 0; j < m; j++) {
				map[i][j] = s.charAt(j);
			}
		}

		int ss = 0, ww = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != '#' && visit[i][j] == 0) {
					int s = 0, w = 0;
					Queue<int[]> q = new ArrayDeque<>();
					visit[i][j] = 1;
					q.offer(new int[] {i, j});

					while (!q.isEmpty()) {
						int[] now = q.poll();
						if (map[now[0]][now[1]] == 'v') {
							w++;
						} else if (map[now[0]][now[1]] == 'k') {
							s++;
						}

						for (int k = 0; k < 4; k++) {
							int nx = now[0] + dx[k];
							int ny = now[1] + dy[k];
							if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != '#' && visit[nx][ny] == 0) {
								q.offer(new int[] {nx, ny});
								visit[nx][ny] = 1;
							}
						}
					}

					if (s > w) {
						ss += s;
					} else {
						ww += w;
					}
				}
			}
		}
		System.out.println(ss + " " + ww);
	}
}