class Solution {
    static int n;
    public String toBinary(int num) {
        String res = "";
        while (num != 0) {
            res += num % 2;
            num /= 2;
        }
        while(res.length() < n) res += '0';
        return new StringBuffer(res).reverse().toString();
    }

    static char[][] map = new char[16][16];

    public String[] solution(int n, int[] arr1, int[] arr2) {
        Solution.n = n;
        String[] answer = new String[n];
        for (int j = 0; j < n; j++) {
            String s = toBinary(arr1[j]);
            String s2 = toBinary(arr2[j]);
            String temp = "";
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '1' || s2.charAt(i) == '1') temp += '#';
                else temp += ' ';
            }
            answer[j] = temp;
        }
        return answer;
    }
}