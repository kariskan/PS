import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[] a = new int[1000001];

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n, k;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int g = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			a[x] = g;
		}

		long s = 0;
		for (int i = 0; i <= Math.min(k * 2, 1000000); i++) {
			s += a[i];
		}
		long ans = s;
		for (int i = Math.min(k * 2, 1000000) + 1; i < 1000000; i++) {
			s = s + a[i] - a[i - 2 * k - 1];
			ans = Math.max(ans, s);
		}

		System.out.println(ans);
	}
}