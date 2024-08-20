import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int[][] inp = new int[n][4];
		int[] ab = new int[n * n];
		int[] cd = new int[n * n];

		for (int i = 0; i < n; i++) {
			var st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 4; j++) {
				inp[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int idx = 0;
		int idx2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ab[idx++] = inp[i][0] + inp[j][1];
				cd[idx2++] = inp[i][2] + inp[j][3];
			}
		}

		Arrays.sort(ab);
		Arrays.sort(cd);

		long ans = 0;
		for (int i = 0; i < n * n; i++) {
			int left = 0, right = n * n - 1;

			long upper = (long)n * n, lower = (long)n * n;
			while (left <= right) {
				int mid = (left + right) / 2;

				if (-ab[i] < cd[mid]) {
					right = mid - 1;
					upper = mid;
				} else {
					left = mid + 1;
				}
			}

			left = 0;
			right = n * n - 1;
			while (left <= right) {
				int mid = (left + right) / 2;

				if (-ab[i] <= cd[mid]) {
					right = mid - 1;
					lower = mid;
				} else {
					left = mid + 1;
				}
			}

			ans += upper - lower;
		}

		System.out.println(ans);
	}
}