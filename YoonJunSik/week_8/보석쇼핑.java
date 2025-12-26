import java.util.*;

class Solution {
    public int[] solution(String[] gems) {

        // 전체 보석 종류 수
        Set<String> gemSet = new HashSet<>(Arrays.asList(gems));
        int totalKinds = gemSet.size();

        Map<String, Integer> map = new HashMap<>();

        int left = 0;
        int minLen = Integer.MAX_VALUE;
        int[] answer = new int[2];

        for(int right = 0; right < gems.length; right++) {
            // right 확장
            map.put(gems[right], map.getOrDefault(gems[right], 0) + 1);

            // 모든 종류 포함되면 left 줄이기
            while(map.size() == totalKinds) {
                int currLen = right - left;

                if(currLen < minLen) {
                    minLen = currLen;
                    answer[0] = left + 1;   // 진열대 번호는 1부터
                    answer[1] = right + 1;
                }

                // left 축소
                map.put(gems[left], map.get(gems[left]) - 1);
                if(map.get(gems[left]) == 0) {
                    map.remove(gems[left]);
                }
                left++;
            }
        }

        return answer;
    }
}
