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

		int n, m;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		List<List<Integer>> v = new ArrayList<>();
		for (int i = 0; i <= n; i++) {
			v.add(new ArrayList<>());
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			v.get(b).add(a);
		}
		Queue<Integer> q = new ArrayDeque<>();
		int[] vis = new int[n + 1];
		int x = Integer.parseInt(br.readLine());
		q.offer(x);
		vis[x] = 1;
		int ans = 0;
		while (!q.isEmpty()) {
			int now = q.poll();
			ans++;
			for (var c : v.get(now)) {
				if (vis[c] == 0) {
					vis[c] = 1;
					q.offer(c);
				}
			}
		}
		System.out.println(ans - 1);
	}
}