import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		int[][] board = new int[52][52];

		int n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			char start = s.charAt(0);
			char end = s.charAt(s.length() - 1);
			board[getIdxByChar(start)][getIdxByChar(end)] = 1;
		}

		for (int k = 0; k < 52; k++) {
			for (int i = 0; i < 52; i++) {
				for (int j = 0; j < 52; j++) {
					if (i == j) {
						continue;
					}
					if (board[i][k] == 1 && board[k][j] == 1) {
						board[i][j] = 1;
					}
				}
			}
		}

		int cnt = 0;
		List<String> ans = new ArrayList<>();
		for (int i = 0; i < 52; i++) {
			for (int j = 0; j < 52; j++) {
				if (i == j) {
					continue;
				}
				if (board[i][j] == 1) {
					cnt++;
					ans.add(getCharByIdx(i) + " => " + getCharByIdx(j));
				}
			}
		}
		System.out.println(cnt);
		for (String s : ans) {
			System.out.println(s);
		}
	}

	static int getIdxByChar(char c) {
		if (c >= 'A' && c <= 'Z') {
			return c - 'A';
		}
		return c - 'a' + 26;
	}

	static char getCharByIdx(int idx) {
		if (idx < 26) {
			return (char)(idx + 'A');
		}
		return (char)(idx - 26 + 'a');
	}
}