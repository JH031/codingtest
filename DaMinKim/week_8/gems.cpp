#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, 0};
    
    // 1. 전체 보석 종류의 개수 파악
    set<string> total_kinds(gems.begin(), gems.end());
    int target_count = total_kinds.size();
    
    // 구간 내 보석의 개수를 저장할 map
    unordered_map<string, int> gem_map;
    
    int start = 0, end = 0;
    int min_len = 100001; // 최대 길이보다 크게 초기화
    
    // 2. 투 포인터 탐색
    while (true) {
        // 모든 종류를 포함하고 있다면 start를 이동시켜 구간을 줄임
        if (gem_map.size() == target_count) {
            if (end - start < min_len) {
                min_len = end - start;
                answer = {start + 1, end}; // 1번 진열대부터 시작하므로 +1
            }
            
            gem_map[gems[start]]--;
            if (gem_map[gems[start]] == 0) {
                gem_map.erase(gems[start]);
            }
            start++;
        }
        // 모든 종류를 포함하지 못했다면 end를 이동시켜 보석을 추가
        else if (end == gems.size()) {
            break; // 더 이상 추가할 보석이 없음
        }
        else {
            gem_map[gems[end]]++;
            end++;
        }
    }
    
    return answer;
}