import java.util.*;

class Solution {
    public int solution(int N, int number)
    {

        if(N == number) return 1;

        List<Set<Integer>> dp = new ArrayList<>();

        for(int i = 0; i <= 8; i++)
        {
            dp.add(new HashSet<>());
        }

        for(int i = 1; i <= 8; i++)
        {

            // N을 i번 이어붙인 수 (e.g., 5 → 55 → 555)
            int repeatedN = 0;
            for(int j = 0; j < i; j++)
            {
                repeatedN = repeatedN * 10 + N;
            }
            dp.get(i).add(repeatedN);

            // j + (i-j) 을 이용해 모든 조합 생성
            for(int j = 1; j < i; j++)
            {
                Set<Integer> set1 = dp.get(j);
                Set<Integer> set2 = dp.get(i - j);

                for(int a : set1)
                {
                    for(int b : set2)
                    {
                        dp.get(i).add(a + b);
                        dp.get(i).add(a - b);
                        dp.get(i).add(a * b);
                        if (b != 0) dp.get(i).add(a / b);
                    }
                }
            }

            // 목표 number가 있는지 확인
            if(dp.get(i).contains(number))
            {
                return i;
            }
        }

        return -1;
    }
}