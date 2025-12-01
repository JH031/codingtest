import java.util.*;

class Solution {
    public String solution(String number, int k)
    {
        StringBuilder answer = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        for(char c : number.toCharArray())
        {

            while(!stack.isEmpty() && k > 0 && stack.peek() < c)
            {
                stack.pop();
                k--;
            }

            stack.push(c);
        }

        // 아직 제거할 게 남으면 뒤에서 제거
        while(k > 0)
        {
            stack.pop();
            k--;
        }

        // 스택에서 문자열 만들기
        for(char c : stack)
        {
            answer.append(c);
        }
        return answer.toString();
    }
}