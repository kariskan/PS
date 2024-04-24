import java.util.*;

class Solution {
    public int solution(int coin, int[] cards) {
        int answer = 0;
        Set<Integer> mine = new HashSet<>();
        Set<Integer> discard = new HashSet<>();
        
        for (int i = 0; i < cards.length / 3; i++) {
            mine.add(cards[i]);
        }
        
        for (int i = cards.length / 3; i < cards.length; i += 2) {
            discard.add(cards[i]);
            discard.add(cards[i + 1]);
            boolean flag = false;
            // 내꺼 2개
            for (int j : mine) {
                for (int k : mine) {
                    if (j == k) {
                        continue;
                    }
                    if (j + k == cards.length + 1) {
                        mine.remove(j);
                        mine.remove(k);
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            // 내꺼 1개, 버린거 1개
            if (!flag && coin > 0) {
                for (int j : mine) {
                    if (discard.contains(cards.length + 1 - j)) {
                        coin--;
                        discard.remove(cards.length + 1 - j);
                        flag = true;
                        break;
                    }
                }
            }
            // 버린거 2개
            if (!flag && coin >= 2) {
                for (int j : discard) {
                    for (int k : discard) {
                        if (j == k) {
                            continue;
                        }
                        if (j + k == cards.length + 1) {
                            coin -= 2;
                            discard.remove(j);
                            discard.remove(k);
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
            }
            if (!flag) {
                return (i - cards.length / 3) / 2 + 1;
            }
        }
        return (cards.length - cards.length / 3) / 2 + 1;
    }
}