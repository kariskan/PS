import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int n;
	static int[][] a;
	static int[] idx;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		a = new int[n][n];
		idx = new int[n];
		var q = new PriorityQueue<Integer>(Comparator.reverseOrder());
		for (int i = 0; i < n; i++) {
			var st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
				q.offer(a[i][j]);
			}
			idx[i] = n - 1;
		}
		int c = n;
		while (c-- > 1) {
			int max = 0;
			for (int i = 0; i < n; i++) {
				if (idx[i] < 0) {
					continue;
				}
				max = Math.max(max, a[idx[i]][i]);
			}
			q.poll();
		}
		System.out.println(q.peek());
	}
}