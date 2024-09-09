import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int n;
	static int[] dp = new int[1000001];
	static int[] a = new int[1000001];

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		var st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}

		List<Integer> v = new ArrayList<>();
		v.add(a[0]);
		for (int i = 1; i < n; i++) {
			if (a[i] > v.get(v.size() - 1)) {
				v.add(a[i]);
			} else {
				int idx = 0;
				int l = 0, r = v.size() - 1;
				while (l <= r) {
					int mid = (l + r) / 2;
					if (v.get(mid) >= a[i]) {
						r = mid - 1;
						idx = mid;
					} else {
						l = mid + 1;
					}
				}
				v.set(idx, a[i]);
			}
			// System.out.println(v);
		}

		System.out.println(v.size());
	}
}