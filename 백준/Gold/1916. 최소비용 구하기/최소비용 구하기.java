import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		int n, m;
		var br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());
		List<List<int[]>> v = new ArrayList<>();
		for (int i = 0; i <= n; i++) {
			v.add(new ArrayList<>());
		}
		for (int i = 0; i < m; i++) {
			int a, b, c;
			var st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			v.get(a).add(new int[] {b, c});
		}

		int[] dis = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			dis[i] = Integer.MAX_VALUE;
		}

		int x, y;
		var st = new StringTokenizer(br.readLine());
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());

		dis[x] = 0;
		Queue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
		pq.offer(new int[] {0, x});

		while (!pq.isEmpty()) {
			int[] now = pq.poll();

			if (dis[now[1]] < now[0]) {
				continue;
			}

			for (var i : v.get(now[1])) {
				int nx = i[0];
				int nCost = i[1] + now[0];
				if (dis[nx] > nCost) {
					dis[nx] = nCost;
					pq.offer(new int[] {nCost, nx});
				}
			}
		}

		System.out.println(dis[y]);
	}
}
