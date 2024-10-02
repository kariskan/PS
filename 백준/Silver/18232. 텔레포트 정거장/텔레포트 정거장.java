import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int n;
	static int[][] ans;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n, m, s, e;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		List<List<Integer>> tp = new ArrayList<>();
		for (int i = 0; i <= n; i++) {
			tp.add(new ArrayList<>());
		}
		int[] vis = new int[n + 1];
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			tp.get(a).add(b);
			tp.get(b).add(a);
		}

		Queue<Integer> q = new ArrayDeque<>();
		vis[s] = 1;
		q.offer(s);

		while (!q.isEmpty()) {
			int now = q.poll();

			if (now == e) {
				System.out.println(vis[now] - 1);
				break;
			}

			if (now - 1 > 0 && vis[now - 1] == 0) {
				vis[now - 1] = vis[now] + 1;
				q.offer(now - 1);
			}
			if (now + 1 < n + 1 && vis[now + 1] == 0) {
				vis[now + 1] = vis[now] + 1;
				q.offer(now + 1);
			}
			for (int t : tp.get(now)) {
				if (vis[t] == 0) {
					vis[t] = vis[now] + 1;
					q.offer(t);
				}
			}
		}
	}
}