import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int[][] map = new int[100][100];

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int r, c, k;
		var st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		for (int i = 0; i < 3; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 3; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		r--;
		c--;

		int n = 3, m = 3;
		int cnt = 0;

		while (true) {
			if (map[r][c] == k) {
				System.out.println(cnt);
				return;
			}
			if (++cnt > 100) {
				break;
			}
			if (n >= m) {
				for (int i = 0; i < n; i++) {
					List<int[]> v = new ArrayList<>();
					int[] arr = new int[101];
					for (int j = 0; j < 100; j++) {
						if (map[i][j] == 0) {
							continue;
						}
						arr[map[i][j]]++;
						map[i][j] = 0;
					}
					for (int j = 0; j <= 100; j++) {
						if (arr[j] > 0) {
							v.add(new int[] {j, arr[j]});
						}
					}
					v.sort(Comparator.comparing((int[] a) -> a[1]).thenComparing(a -> a[0]));
					m = Math.max(m, v.size() * 2);
					for (int j = 0; j < 50; j++) {
						if (v.size() == j) {
							break;
						}
						map[i][j * 2] = v.get(j)[0];
						map[i][j * 2 + 1] = v.get(j)[1];
					}

				}
			} else {
				for (int j = 0; j < m; j++) {
					List<int[]> v = new ArrayList<>();
					int[] arr = new int[101];
					for (int i = 0; i < 100; i++) {
						if (map[i][j] == 0) {
							continue;
						}
						arr[map[i][j]]++;
						map[i][j] = 0;
					}
					for (int i = 0; i <= 100; i++) {
						if (arr[i] > 0) {
							v.add(new int[] {i, arr[i]});
						}
					}
					v.sort(Comparator.comparing((int[] a) -> a[1]).thenComparing(a -> a[0]));
					n = Math.max(n, v.size() * 2);
					for (int i = 0; i < 50; i++) {
						if (v.size() == i) {
							break;
						}
						map[i * 2][j] = v.get(i)[0];
						map[i * 2 + 1][j] = v.get(i)[1];
					}
				}
			}
		}
		System.out.println(-1);
	}
}