import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static List<List<Integer>> v = new ArrayList<>();
	static List<long[]> inp = new ArrayList<>();
	static int n, answer = 0;
	static int node;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		for (int i = 0; i <= n; i++) {
			v.add(new ArrayList<>());
		}
		inp.add(new long[] {});
		for (int i = 0; i < n; i++) {
			var st = new StringTokenizer(br.readLine());
			long a = Integer.parseInt(st.nextToken());
			long b = Integer.parseInt(st.nextToken());
			long c = Integer.parseInt(st.nextToken());
			inp.add(new long[] {a, b, c});
		}

		for (int i = 1; i <= n; i++) {
			long minR = Long.MAX_VALUE;
			int idx = -1;
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				long r1 = inp.get(i)[2];
				long r2 = inp.get(j)[2];
				double dis = Math.sqrt(
					Math.pow(inp.get(i)[0] - inp.get(j)[0], 2) + Math.pow(inp.get(i)[1] - inp.get(j)[1], 2));
				if (dis > r1 + r2) {
					continue;
				}
				if (dis < Math.abs(r1 - r2) && r1 < r2 && minR > r2) {
					minR = r2;
					idx = j;
				}
			}
			if (idx != -1) {
				v.get(i).add(idx);
				v.get(idx).add(i);
			}
		}

		for (int i = 1; i <= n; i++) {
			boolean flag = false;
			for (int j = 0; j < v.get(i).size(); j++) {
				int n2 = v.get(i).get(j);
				if (inp.get(i)[2] < inp.get(n2)[2]) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				v.get(0).add(i);
				v.get(i).add(0);
			}
		}

		go(0, -1, 0);
		go(node, -1, 0);
		System.out.println(answer);
	}

	static void go(int idx, int pre, int count) {
		if (answer < count) {
			answer = count;
			node = idx;
		}
		for (var i : v.get(idx)) {
			if (i != pre) {
				go(i, idx, count + 1);
			}
		}
	}
}