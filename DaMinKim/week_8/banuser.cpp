#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool visited[8];
set<set<string>> result_set; // 최종 제재 아이디 목록들의 집합 (중복 제거용)

// user_id가 banned_id 패턴과 일치하는지 확인하는 함수
bool isMatched(string user, string banned) {
    if (user.length() != banned.length()) return false;
    
    for (int i = 0; i < user.length(); i++) {
        if (banned[i] == '*') continue;
        if (user[i] != banned[i]) return false;
    }
    return true;
}

void dfs(int index, vector<string>& user_id, vector<string>& banned_id, set<string>& current_list) {
    // 모든 banned_id에 대해 매칭을 완료했을 때
    if (index == banned_id.size()) {
        result_set.insert(current_list); // 현재까지 모인 아이디 세트를 결과 세트에 삽입
        return;
    }

    for (int i = 0; i < user_id.size(); i++) {
        // 이미 사용 중인 아이디거나, 패턴이 일치하지 않으면 패스
        if (visited[i] || !isMatched(user_id[i], banned_id[index])) continue;

        visited[i] = true;
        current_list.insert(user_id[i]);
        
        dfs(index + 1, user_id, banned_id, current_list);
        
        // 백트래킹: 상태 복구
        current_list.erase(user_id[i]);
        visited[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    set<string> current_list;
    dfs(0, user_id, banned_id, current_list);
    
    return result_set.size();
}