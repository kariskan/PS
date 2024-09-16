import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int[][] a;
	static int n, m;
	static int[] dx = {0, 0, 1, -1};
	static int[] dy = {1, -1, 0, 0};
	static int ans;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		a = new int[n][n];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		while (group()) {
			gravity();
			rotate();
			gravity();
//			System.out.println("ans: " + ans);
		}

		System.out.println(ans);
	}

	static boolean group() {
		boolean[][] vis = new boolean[n][n];
		List<Group> groups = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!vis[i][j] && a[i][j] > 0) {
					Queue<int[]> q = new ArrayDeque<>();
					vis[i][j] = true;
					q.offer(new int[]{i, j});

					int size = 0;
					int rainbow = 0;
					int row = n;
					int col = n;
					List<int[]> v = new ArrayList<>();

					while (!q.isEmpty()) {
						var now = q.poll();

						size++;
						if (a[now[0]][now[1]] == 0) {
							rainbow++;
						} else {
							row = Math.min(row, now[0]);
							col = Math.min(col, now[1]);
						}
						v.add(new int[]{now[0], now[1]});

						for (int k = 0; k < 4; k++) {
							int nx = now[0] + dx[k];
							int ny = now[1] + dy[k];
							if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && (a[nx][ny] == 0
								|| a[nx][ny] == a[i][j])) {
								vis[nx][ny] = true;
								q.offer(new int[]{nx, ny});
							}
						}
					}
					if (size >= 2) {
						groups.add(new Group(size, rainbow, row, col, v));
					}
					for (int i1 = 0; i1 < n; i1++) {
						for (int j1 = 0; j1 < n; j1++) {
							if (a[i1][j1] == 0) {
								vis[i1][j1] = false;
							}
						}
					}
				}
			}
		}
		if (groups.isEmpty()) {
			return false;
		}
		Collections.sort(groups);

		for (int i = 0; i < groups.get(0).v.size(); i++) {
			int[] now = groups.get(0).v.get(i);
			a[now[0]][now[1]] = -2;
		}
		ans += groups.get(0).size * groups.get(0).size;

//		System.out.println("group");
//		print();
		return true;
	}

	static void rotate() {
		int[][] temp = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = a[j][n - i - 1];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = temp[i][j];
			}
		}
//		System.out.println("rotate");
//		print();
	}

	static void gravity() {
		for (int j = 0; j < n; j++) {
			for (int i = n - 1; i >= 0; i--) {
				if (a[i][j] >= 0) {
					int idx = n;
					for (int k = i + 1; k < n; k++) {
						if (a[k][j] >= -1) {
							idx = k;
							break;
						}
					}
					int temp = a[i][j];
					a[i][j] = -2;
					a[idx - 1][j] = temp;
				}
			}
		}

//		System.out.println("gravity");
//		print();
	}

	static void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}
	}

	static class Group implements Comparable<Group> {

		public int size;
		public int rainbow;
		public int stRow;
		public int stCol;
		public List<int[]> v;

		public Group(int size, int rainbow, int stRow, int stCol, List<int[]> v) {
			this.size = size;
			this.rainbow = rainbow;
			this.stRow = stRow;
			this.stCol = stCol;
			this.v = v;
		}

		@Override
		public int compareTo(Group o) {
			if (this.size == o.size) {
				if (this.rainbow == o.rainbow) {
					if (this.stRow == o.stRow) {
						return o.stCol - this.stCol;
					}
					return o.stRow - this.stRow;
				}
				return o.rainbow - this.rainbow;
			}
			return o.size - this.size;
		}
	}
}