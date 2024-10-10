import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

	static int n;
	static int[][] a;
	static int ans;
	static boolean brk;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int l, w, h;
		var st = new StringTokenizer(br.readLine());
		l = Integer.parseInt(st.nextToken());
		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(br.readLine());
		a = new int[n][2];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			a[i][0] = (1 << Integer.parseInt(st.nextToken()));
			a[i][1] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(a, Comparator.comparing(b -> -b[0]));

		go(l, w, h, 0);
		if (brk) {
			ans = -1;
		}
		System.out.println(ans);
	}

	static void go(int l, int w, int h, int idx) {
		if (l <= 0 || w <= 0 || h <= 0) {
			return;
		}
//		System.out.println(l + " " + w + " " + h);
		int min = Math.min(l, Math.min(w, h));

		boolean flag = false;
		for (int i = idx; i < n; i++) {
			if (min < a[i][0] || a[i][1] == 0) {
				continue;
			}
			a[i][1]--;
			ans++;
			go(a[i][0], w - a[i][0], a[i][0], i);
			go(l - a[i][0], w, a[i][0], i);
			go(l, w, h - a[i][0], i);
			flag = true;
			break;
		}
		if (!flag) {
			brk = true;
		}
	}
}