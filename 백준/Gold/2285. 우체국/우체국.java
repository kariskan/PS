import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static List<int[]> arr = new ArrayList<>();
	static int n;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());

		long total = 0;
		for (int i = 0; i < n; i++) {
			int a, b;
			var st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			arr.add(new int[] {a, b});
			total += b;
		}

		arr.sort(Comparator.comparing(a -> a[0]));

		long left = 0, right = total;
		long ans = Long.MAX_VALUE;
		int idx = 0;
		for (int i = 0; i < n; i++) {
			right -= arr.get(i)[1];
			if (Math.abs(left - right) < ans) {
				ans = Math.abs(left - right);
				idx = arr.get(i)[0];
			}
			left += arr.get(i)[1];
		}

		System.out.println(idx);
	}
}