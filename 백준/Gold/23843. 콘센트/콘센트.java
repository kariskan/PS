import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int[] a = new int[10001];

	public static void main(String[] args) throws Exception {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
		int n = Integer.parseInt(stringTokenizer.nextToken());
		int m = Integer.parseInt(stringTokenizer.nextToken());
		stringTokenizer = new StringTokenizer(bufferedReader.readLine());
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(stringTokenizer.nextToken());
		}

		Arrays.sort(a, 0, n);

		Queue<Integer> pq = new PriorityQueue<>();

		int idx = n - 1;
		while (idx >= 0 && pq.size() < m) {
			pq.offer(a[idx--]);
		}

		for (int i = idx; i >= 0; i--) {
			int t = pq.poll() + a[i];
			pq.offer(t);
		}

		int ans = 0;
		while (!pq.isEmpty()) {
			ans = pq.poll();
		}
		System.out.println(ans);
	}
}
