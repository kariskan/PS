import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int n, q;
	static int[] mon = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	static List<List<Long>> v = new ArrayList<>();

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		var st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		q = Integer.parseInt(st.nextToken());
		for (int i = 0; i <= 6; i++) {
			v.add(new ArrayList<>());
		}

		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			int lv = Integer.parseInt(s.split("#")[1]);
			// System.out.println(lv + " " + getTime(s));
			v.get(lv).add(getTime(s));
		}

		for (int i = 1; i <= 6; i++) {
			v.get(i).sort(Comparator.naturalOrder());
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < q; i++) {
			String s = br.readLine();
			String[] split = s.split("#");
			long startTime = getTime(split[0]);
			long endTime = getTime(split[1]);
			int lv = Integer.parseInt(split[2]);
			// System.out.println(startTime + " " + endTime + " " + lv);

			int cnt = 0;
			for (int j = lv; j <= 6; j++) {
				cnt += getLogCnt(j, startTime, endTime);
			}

			sb.append(cnt).append("\n");
			// System.out.println(cnt);
		}

		System.out.println(sb);
	}

	static int getLogCnt(int lv, long startTime, long endTime) {
		int l = 0, r = v.get(lv).size() - 1;

		int start = -1, end = -1;
		while (l <= r) {
			int mid = (l + r) / 2;

			if (v.get(lv).get(mid) >= startTime) {
				r = mid - 1;
				start = mid;
			} else {
				l = mid + 1;
			}
		}
		l = 0;
		r = v.get(lv).size() - 1;

		while (l <= r) {
			int mid = (l + r) / 2;

			if (v.get(lv).get(mid) <= endTime) {
				l = mid + 1;
				end = mid;
			} else {
				r = mid - 1;
			}
		}
		// System.out.println("start: " + start + " end: " + end);
		if (start == -1) {
			return 0;
		}
		return end - start + 1;
	}

	static long getTime(String s) {
		String[] s1 = s.split(" "); // 2021-04-05, 17:17:11#1
		String[] s2 = s1[0].split("-"); // 2021,04,05
		String[] s3 = s1[1].split("#"); // 17:17:11, 1
		String[] s4 = s3[0].split(":"); // 17,17,11

		int year = Integer.parseInt(s2[0]);
		int month = Integer.parseInt(s2[1]);
		int day = Integer.parseInt(s2[2]);
		int hour = Integer.parseInt(s4[0]);
		int minute = Integer.parseInt(s4[1]);
		int second = Integer.parseInt(s4[2]);

		long sum = second + minute * 60L + hour * 3600L + (day - 1) * 3600 * 24L;
		int yearDay = 0;
		for (int i = 1; i < month; i++) {
			if (i == 2 && year % 4 == 0) {
				yearDay += 29;
			} else {
				yearDay += mon[i];
			}
		}
		sum += yearDay * 3600 * 24L;

		yearDay = 0;
		for (int i = 2000; i < year; i++) {
			if (i % 4 == 0) {
				yearDay += 366;
			} else {
				yearDay += 365;
			}
		}

		return sum + yearDay * 3600 * 24L;
	}
}