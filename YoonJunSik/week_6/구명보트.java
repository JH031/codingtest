import java.util.*;

class Solution {
    public int solution(int[] people, int limit)
    {
        Arrays.sort(people);

        int left = 0;
        int right = people.length - 1;
        int boats = 0;

        while(left <= right)
        {
            // 둘이 같이 탈 수 있으면 같이 태움
            if(people[left] + people[right] <= limit)
            {
                left++;
            }
            // 무거운 사람은 항상 보트에 탑승
            right--;
            boats++;
        }

        return boats;
    }
}