import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n, l, r, x;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		l = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}

		int ans = 0;
		for (int i = 0; i < (1 << n); i++) {
			int sum = 0;
			int min = Integer.MAX_VALUE;
			int max = Integer.MIN_VALUE;
			for (int j = 0; j < n; j++) {
				if ((i & (1 << j)) > 0) {
					sum += a[j];
					min = Math.min(min, a[j]);
					max = Math.max(max, a[j]);
				}
			}
			if (sum >= l && sum <= r && max - min >= x) {
				ans++;
			}
		}
		System.out.println(ans);
	}
}