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

		List<List<Integer>> v = new ArrayList<>();
		int n = Integer.parseInt(br.readLine());
		for (int i = 0; i <= n; i++) {
			v.add(new ArrayList<>());
		}
		var st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());

		int m = Integer.parseInt(br.readLine());
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			v.get(x).add(y);
			v.get(y).add(x);
		}

		int[] vis = new int[n + 1];
		vis[a] = 1;
		Queue<Integer> q = new ArrayDeque<>();
		q.offer(a);

		while (!q.isEmpty()) {
			int now = q.poll();

			for (var c : v.get(now)) {
				if (vis[c] == 0) {
					vis[c] = vis[now] + 1;
					q.offer(c);
				}
			}
		}

		if (vis[b] == 0) {
			System.out.println(-1);
		} else {
			System.out.println(vis[b] - 1);
		}
	}
}