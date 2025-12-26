class Solution {
    public String solution(int n, int t, int m, int p) {

        StringBuilder all = new StringBuilder();
        StringBuilder answer = new StringBuilder();

        int num = 0;

        // 충분한 길이의 전체 문자열 생성
        while(all.length() < t * m) {
            all.append(Integer.toString(num, n).toUpperCase());
            num++;
        }

        // 튜브 차례만 추출
        for(int i = 0; i < all.length() && answer.length() < t; i++) {
            if(i % m == p - 1) {
                answer.append(all.charAt(i));
            }
        }
        return answer.toString();
    }
}
