import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n, m;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		long[] a = new long[m];
		st = new StringTokenizer(br.readLine());
		long ma = 0;
		for (int i = 0; i < m; i++) {
			a[i] = Integer.parseInt(st.nextToken());
			ma = Math.max(ma, a[i]);
		}

		long left = 0, right = (n - 1) * ma;
		long t = 0;

		while (left <= right) {
			long mid = (left + right) / 2;

			long sum = 0;
			for (int i = 0; i < m; i++) {
				sum += mid / a[i] + 1;
			}

			if (sum >= n) {
				right = mid - 1;
				t = mid;
			} else {
				left = mid + 1;
			}
		}

		long s = 0;
		if (t != 0) {
			for (int i = 0; i < m; i++) {
				s += (t - 1) / a[i] + 1;
			}
		}
		for (int i = 0; i < m; i++) {
			if (t % a[i] == 0) {
				s++;
				if (s == n) {
					System.out.println(i + 1);
					return;
				}
			}
		}
	}
}