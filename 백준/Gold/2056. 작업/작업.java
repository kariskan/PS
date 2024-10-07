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

		int n = Integer.parseInt(br.readLine());
		int[] time = new int[n + 1];
		int[] in = new int[n + 1];
		List<List<Integer>> v = new ArrayList<>();
		for (int i = 0; i <= n; i++) {
			v.add(new ArrayList<>());
		}
		for (int i = 1; i <= n; i++) {
			var st = new StringTokenizer(br.readLine());
			int t = Integer.parseInt(st.nextToken());
			time[i] = t;
			int m = Integer.parseInt(st.nextToken());
			for (int j = 0; j < m; j++) {
				v.get(Integer.parseInt(st.nextToken())).add(i);
				in[i]++;
			}
		}

		int ans = 0;
		Queue<int[]> q = new ArrayDeque<>();
		for (int i = 1; i <= n; i++) {
			if (in[i] == 0) {
				q.offer(new int[]{i, time[i]});
			}
		}

		int[] max = new int[n + 1];
		while (!q.isEmpty()) {
			var now = q.poll();

//			System.out.println(now[0] + " " + now[1]);
			ans = Math.max(ans, now[1]);
			max[now[0]] = Math.max(max[now[0]], now[1]);

			for (var next : v.get(now[0])) {
				max[next] = Math.max(max[next], now[1]);
				if (--in[next] == 0) {
					q.offer(new int[]{next, max[next] + time[next]});
				}
			}
		}

		System.out.println(ans);
	}
}