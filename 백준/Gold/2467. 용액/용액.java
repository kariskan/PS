import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int[] a = new int[n];
		var st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}

		int l = 0, r = n - 1;
		int ans = Integer.MAX_VALUE;
		int ansl = a[0], ansr = a[n - 1];
		while (l < r) {
			int abs = Math.abs(a[l] + a[r]);
			if (ans > abs) {
				ans = abs;
				ansl = a[l];
				ansr = a[r];
			}
			if (a[l] + a[r] > 0) {
				r--;
			} else {
				l++;
			}
		}
		System.out.println(ansl + " " + ansr);
	}
}