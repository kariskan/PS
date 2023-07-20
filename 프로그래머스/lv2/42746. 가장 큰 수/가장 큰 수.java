import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        String[] list = Arrays.stream(numbers).mapToObj(String::valueOf).toArray(String[]::new);
        
        Arrays.sort(list, (s1, s2) -> (s2+s1).compareTo(s1+s2));
        for (String s : list) {
            answer += s;
        }
        
        if (answer.charAt(0) == '0') {
            return "0";
        }
        
        return answer;
    }
}