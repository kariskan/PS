import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n;
		n = Integer.parseInt(br.readLine());

		int[][] a = new int[n][2];
		for (int i = 0; i < n; i++) {
			var st = new StringTokenizer(br.readLine());
			a[i][0] = Integer.parseInt(st.nextToken());
			a[i][1] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(a, Comparator.comparingInt((int[] a2) -> a2[1]).thenComparing(a2 -> a2[0]));

		int now = 0;
		int ans = 1;
		for (int i = now + 1; i < n; i++) {
			if (a[now][1] <= a[i][0]) {
				now = i;
				ans++;
			}
		}

		System.out.println(ans);
	}
}