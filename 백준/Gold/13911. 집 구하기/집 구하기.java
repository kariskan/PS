import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int v;
	static long e, m, x, s, y;
	static List<List<long[]>> list = new ArrayList<>();
	static boolean[] isM, isS;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		v = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		isM = new boolean[v + 3];
		isS = new boolean[v + 3];
		for (int i = 0; i <= v + 2; i++) {
			list.add(new ArrayList<>());
		}
		for (int i = 0; i < e; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			list.get(a).add(new long[]{b, c});
			list.get(b).add(new long[]{a, c});
		}

		st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < m; i++) {
			int a = Integer.parseInt(st.nextToken());
			isM[a] = true;
			list.get(v + 1).add(new long[]{a, 0});
		}
		st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < s; i++) {
			int a = Integer.parseInt(st.nextToken());
			isS[a] = true;
			list.get(v + 2).add(new long[]{a, 0});
		}

		long[] mac = dijk(v + 1);
		long[] star = dijk(v + 2);
//		System.out.println(Arrays.toString(mac));
//		System.out.println(Arrays.toString(star));

		long ans = -1;
		for (int i = 1; i <= v; i++) {
			if (!isM[i] && !isS[i] && mac[i] <= x && star[i] <= y) {
				if (ans == -1 || ans > mac[i] + star[i]) {
					ans = mac[i] + star[i];
				}
			}
		}
		System.out.println(ans);
	}
	static long[] dijk(int start) {
		long[] dis = new long[v + 3];
		Arrays.fill(dis, Long.MAX_VALUE);
		var pq = new PriorityQueue<long[]>(Comparator.comparing(a -> a[0]));
		dis[start] = 0;
		pq.offer(new long[]{0, start});

		while (!pq.isEmpty()) {
			long[] now = pq.poll();

			if (dis[(int) now[1]] < now[0]) {
				continue;
			}

			for (var i : list.get((int) now[1])) {
				long nxCost = now[0] + i[1];
				long nx = i[0];
				if (nxCost < dis[(int) nx]) {
					dis[(int) nx] = nxCost;
					pq.offer(new long[]{nxCost, nx});
				}
			}
		}
		return dis;
	}
}