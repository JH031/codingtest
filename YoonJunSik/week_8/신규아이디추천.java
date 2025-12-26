class Solution {
    public String solution(String new_id) {

        // 1단계: 대문자 → 소문자
        String id = new_id.toLowerCase();

        // 2단계: 허용되지 않은 문자 제거
        id = id.replaceAll("[^a-z0-9-_.]", "");

        // 3단계: 마침표 2번 이상 → 하나의 마침표
        id = id.replaceAll("\\.+", ".");

        // 4단계: 처음이나 끝의 마침표 제거
        id = id.replaceAll("^\\.|\\.$", "");

        // 5단계: 빈 문자열이면 "a"
        if(id.isEmpty()) {
            id = "a";
        }

        // 6단계: 길이 16자 이상이면 15자로 자르기
        if(id.length() >= 16) {
            id = id.substring(0, 15);
            id = id.replaceAll("\\.$", "");
        }

        // 7단계: 길이가 2 이하라면 마지막 문자 반복
        while(id.length() < 3) {
            id += id.charAt(id.length() - 1);
        }
        return id;
    }
}
