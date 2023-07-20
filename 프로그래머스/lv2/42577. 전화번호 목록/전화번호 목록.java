import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        Set<String> set = new HashSet<>();
        
        for (String s : phone_book) {
            for (int i = 1; i < s.length(); i++) {
                set.add(s.substring(0, i));
            }
        }
        for (String s : phone_book) {
            if (set.contains(s)) {
                return false;
            }
        }
        
        return true;
    }
}