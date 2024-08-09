import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static List<List<int[]>> v = new ArrayList<>();
	static int[][] ans = new int[101][101];
	static int[] in = new int[101];

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n, m;
		n = Integer.parseInt(reader.readLine());
		m = Integer.parseInt(reader.readLine());

		for (int i = 0; i <= n; i++) {
			v.add(new ArrayList<>());
		}

		StringTokenizer st;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			st = new StringTokenizer(reader.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			v.get(a).add(new int[] {b, c});
			v.get(b).add(new int[] {a, c});
			in[a]++;
		}

		Queue<Integer> base = new ArrayDeque<>();
		Queue<Integer> q = new ArrayDeque<>();
		for (int i = 1; i <= n; i++) {
			if (in[i] == 0) {
				q.offer(i);
				ans[i][i] = 1;
				base.offer(i);
			}
		}

		while (!q.isEmpty()) {
			int node = q.poll();

			for (var i : v.get(node)) {
				for (int j = 1; j <= n; j++) {
					ans[node][j] += ans[i[0]][j] * i[1];
				}
				in[i[0]]--;
				if (in[i[0]] == 0) {
					q.offer(i[0]);
				}
			}
		}

		while (!base.isEmpty()) {
			int b = base.poll();
			System.out.println(b + " " + ans[n][b]);
		}
	}
}
