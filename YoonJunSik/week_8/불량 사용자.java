import java.util.*;

class Solution {

    Set<String> resultSet = new HashSet<>();
    boolean[] used;
    String[] user_id, banned_id;

    public int solution(String[] user_id, String[] banned_id) {
        this.user_id = user_id;
        this.banned_id = banned_id;
        this.used = new boolean[user_id.length];

        dfs(0, new ArrayList<>());

        return resultSet.size();
    }

    private void dfs(int depth, List<String> selected) {
        if (depth == banned_id.length) {
            // 순서 무시 → 정렬 후 하나의 문자열로 저장
            List<String> temp = new ArrayList<>(selected);
            Collections.sort(temp);
            resultSet.add(String.join(",", temp));
            return;
        }

        for (int i = 0; i < user_id.length; i++) {
            if (used[i]) continue;
            if (isMatch(user_id[i], banned_id[depth])) {
                used[i] = true;
                selected.add(user_id[i]);

                dfs(depth + 1, selected);

                // 백트래킹
                used[i] = false;
                selected.remove(selected.size() - 1);
            }
        }
    }

    private boolean isMatch(String user, String banned) {
        if (user.length() != banned.length()) return false;

        for (int i = 0; i < user.length(); i++) {
            if (banned.charAt(i) == '*') continue;
            if (user.charAt(i) != banned.charAt(i)) return false;
        }
        return true;
    }
}
