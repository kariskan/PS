import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i);
            
            if (a == '(') {
                st.add(a);
            } else {
                if (st.empty() || st.peek() != '(') {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
}