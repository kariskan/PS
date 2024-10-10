import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		long ans = 0;

		var st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		long m = Long.parseLong(st.nextToken());
		long[][] a = new long[n][2];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			a[i][0] = Long.parseLong(st.nextToken());
			a[i][1] = Long.parseLong(st.nextToken());
		}
		Arrays.sort(a, Comparator.comparing(b -> b[1]));
		for (int i = (int) (m - n); i < m; i++) {
			ans += a[(int) (i - m + n)][0] + a[(int) (i - m + n)][1] * i;
		}
		System.out.println(ans);
	}
}