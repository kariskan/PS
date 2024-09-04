import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[] dice = new int[7];
	static int n, m, x, y, k;
	static int[] dx = {0, 0, 0, -1, 1};
	static int[] dy = {0, 1, -1, 0, 0};

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		int[][] map = new int[20][20];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < k; i++) {
			int a = Integer.parseInt(st.nextToken());
			if (move(a)) {
				if (map[x][y] == 0) {
					map[x][y] = dice[6];
				} else {
					dice[6] = map[x][y];
					map[x][y] = 0;
				}
				// System.out.println(dice[1] + " " + dice[2] + " " + dice[3] + " " + dice[4] + " " + dice[5] + " " + dice[6]);
				System.out.println(dice[1]);
			}
		}
	}

	static boolean move(int dir) {
		x += dx[dir];
		y += dy[dir];
		if (!(x >= 0 && x < n && y >= 0 && y < m)) {
			x -= dx[dir];
			y -= dy[dir];
			return false;
		}
		if (dir == 1) {
			int temp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = temp;
		}
		if (dir == 2) {
			int temp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = temp;
		}
		if (dir == 3) {
			int temp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
		}
		if (dir == 4) {
			int temp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
		}
		return true;
	}
}