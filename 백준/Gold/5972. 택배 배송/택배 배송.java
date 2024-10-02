import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n, m;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		List<List<int[]>> v = new ArrayList<>();
		for (int i = 0; i <= n; i++) {
			v.add(new ArrayList<>());
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			v.get(a).add(new int[]{b, c});
			v.get(b).add(new int[]{a, c});
		}
		Queue<int[]> q = new PriorityQueue<>(Comparator.comparing(a -> a[0]));
		int[] dis = new int[n + 1];
		Arrays.fill(dis, Integer.MAX_VALUE);

		dis[1] = 0;
		q.offer(new int[]{0, 1});

		while (!q.isEmpty()) {
			var now = q.poll();

			if (dis[now[1]] < now[0]) {
				continue;
			}

			for (var c : v.get(now[1])) {
				if (now[0] + c[1] < dis[c[0]]) {
					q.offer(new int[]{now[0] + c[1], c[0]});
					dis[c[0]] = now[0] + c[1];
				}
			}
		}

		System.out.println(dis[n]);
	}
}