import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static int[] ar;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var sb = new StringBuilder();
		String n;
		while ((n = br.readLine()) != null) {
			int a = Integer.parseInt(n);
			int len = (int) Math.pow(3, a);
			ar = new int[len];
			go(0, len - 1);
			for (int i = 0; i < len; i++) {
				if (ar[i] == 0) {
					sb.append(" ");
				} else {
					sb.append("-");
				}
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}

	static void go(int start, int end) {
		if (start > end) {
			return;
		}
		if (start == end) {
			ar[start] = 1;
			return;
		}

		go(start, start + (end - start) / 3);
		go(end - (end - start) / 3, end);
	}
}