import java.util.*;

class Solution {
    public String[] solution(String[] s) {
        String[] answer = new String[s.length];
        
        for (int i = 0; i < s.length; i++) {
            answer[i] = go(s[i]);
        }
        
        return answer;
    }
    
    String go(String s) {
        Stack<Character> st = new Stack<>();
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            st.push(s.charAt(i));
            if (st.size() >= 3) {
                char c1 = st.pop();
                char c2 = st.pop();
                char c3 = st.pop();
                
                if (c1 == '0' && c2 == '1' && c3 == '1') {
                    cnt++;
                    continue;
                }
                st.push(c3);
                st.push(c2);
                st.push(c1);
            }
        }
        String res = "";
        while (!st.isEmpty()) {
            res += st.pop();
        }
        StringBuilder sb = new StringBuilder(res);
        res = sb.reverse().toString();
        int idx = 0;
        for (int i = 0; i < res.length(); i++) {
            if (i < res.length() - 2 && res.charAt(i) == '1' && res.charAt(i + 1) == '1' && res.charAt(i + 2) == '1') {
                idx = i;
                break;
            }
            if (res.charAt(i) == '0') {
                idx = i + 1;
            }
        }
        String dup = "";
        for (int i = 0; i < cnt; i++) {
            dup += "110";
        }
        return res.substring(0, idx) + dup + res.substring(idx);
    }
}