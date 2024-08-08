import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int n, h;
	static int[] arr;
	static int[] rev;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());

		arr = new int[h + 1];
		rev = new int[h + 1];

		for (int i = 0; i < n; i++) {
			int a = Integer.parseInt(br.readLine());
			if (i % 2 == 0) {
				arr[a]++;
			} else {
				rev[a]++;
			}
		}
		for (int i = h - 1; i > 0; i--) {
			arr[i] += arr[i + 1];
			rev[i] += rev[i + 1];
		}
		int ans = Integer.MAX_VALUE;
		int count = 0;

		for (int i = 1; i <= h; i++) {
			if (ans >= arr[i] + rev[h - i + 1]) {
				if (ans != arr[i] + rev[h - i + 1]) {
					count = 0;
				}
				ans = arr[i] + rev[h - i + 1];
				count++;
			}
		}

		System.out.println(ans + " " + count);
	}
}
