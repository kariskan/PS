import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static int n;
	static int[][] ans;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		ans = new int[7][n];
		StringBuilder s = new StringBuilder();
		for (int i = 0; i < n; i++) {
			if (i < n / 2) {
				s.append("A");
			} else {
				s.append("B");
			}
		}

		go('A', 0, n / 2 - 1, 0);
		go('B', n / 2, n - 1, 0);

		StringBuilder sb = new StringBuilder();
		for(int i=0;i<7;i++){
			for(int j=0;j<n;j++){
				if(ans[i][j]==1){
					sb.append('A');
				}else{
					sb.append('B');
				}
			}
			sb.append('\n');
		}
		System.out.println(sb);
	}

	// AAABBBB
	// ABBBBAA
	// ABABAAB
	static void go(char c, int left, int right, int depth) {
		if (depth >= 7) {
			return;
		}
		for (int i = left; i <= right; i++) {
			if (c == 'A') {
				ans[depth][i] = 1;
			} else {
				ans[depth][i] = 2;
			}
		}
		go(c, left, (left + right) / 2, depth + 1);
		go(rev(c), (left + right) / 2 + 1, right, depth + 1);
	}

	static char rev(char c) {
		if (c == 'A') {
			return 'B';
		}
		return 'A';
	}
}