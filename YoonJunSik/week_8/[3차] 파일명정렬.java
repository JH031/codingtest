import java.util.*;

class Solution {

    static class FileInfo {
        String original;
        String head;
        int number;
        int index;

        FileInfo(String original, String head, int number, int index) {
            this.original = original;
            this.head = head;
            this.number = number;
            this.index = index;
        }
    }

    public String[] solution(String[] files) {

        List<FileInfo> list = new ArrayList<>();

        for(int i = 0; i < files.length; i++) {
            String file = files[i];

            int idx = 0;
            int len = file.length();

            // HEAD
            while(idx < len && !Character.isDigit(file.charAt(idx))) {
                idx++;
            }
            String head = file.substring(0, idx).toLowerCase();

            // NUMBER
            int start = idx;
            while(idx < len && Character.isDigit(file.charAt(idx)) && idx - start < 5) {
                idx++;
            }
            int number = Integer.parseInt(file.substring(start, idx));

            list.add(new FileInfo(file, head, number, i));
        }

        // 정렬
        Collections.sort(list, (a, b) -> {
            int headCompare = a.head.compareTo(b.head);
            if(headCompare != 0) return headCompare;

            int numCompare = a.number - b.number;
            if(numCompare != 0) return numCompare;

            return 0; // 입력 순서 유지 (stable sort)
        });

        // 결과 추출
        String[] answer = new String[files.length];
        for(int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i).original;
        }
        return answer;
    }
}
