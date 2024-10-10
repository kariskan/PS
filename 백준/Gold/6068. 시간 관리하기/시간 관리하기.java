import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int[][] a = new int[n][2];
		for (int i = 0; i < n; i++) {
			var st = new StringTokenizer(br.readLine());
			a[i][0] = Integer.parseInt(st.nextToken());
			a[i][1] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(a, Comparator.comparing(b -> b[1]));
		int left = 0, right = a[0][1];
		int ans = -1;
		while (left <= right) {
			int mid = (left + right) / 2;

			int now = mid;
			boolean flag = true;
			for (int i = 0; i < n; i++) {
				now += a[i][0];
				if (now > a[i][1]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				left = mid + 1;
				ans = mid;
			} else {
				right = mid - 1;
			}
		}
		System.out.println(ans);
	}
}