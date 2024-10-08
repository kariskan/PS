import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static List<Integer> a = new ArrayList<>();
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		String s;
		while ((s = br.readLine()) != null) {
			a.add(Integer.parseInt(s));
		}
		go(0, a.size() - 1);
		System.out.println(sb);
	}

	static void go(int l, int r) {
		if (l > r) {
			return;
		}
		boolean flag = false;
		for (int i = l; i <= r; i++) {
			if (a.get(l) < a.get(i)) {
				go(l + 1, i - 1);
				go(i, r);
				flag = true;
				break;
			}
		}
		if (!flag) {
			go(l + 1, r);
		}
		sb.append(a.get(l)).append('\n');
	}
}