#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// 집합의 크기가 작은 순서대로 정렬하기 위한 비교 함수
bool compare(const vector<int>& a, const vector<int>& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> subsets;
    vector<int> current_subset;
    string num_str = "";

    // 1. 문자열 파싱하여 각 집합들을 subsets 벡터에 담기
    for (int i = 1; i < s.length() - 1; i++) {
        if (isdigit(s[i])) {
            num_str += s[i];
        } else if (s[i] == ',' || s[i] == '}') {
            if (!num_str.empty()) {
                current_subset.push_back(stoi(num_str));
                num_str = "";
            }
            if (s[i] == '}') {
                subsets.push_back(current_subset);
                current_subset.clear();
            }
        }
    }

    // 2. 집합의 크기 순으로 오름차순 정렬
    sort(subsets.begin(), subsets.end(), compare);

    // 3. 이전 집합에 없던 원소를 answer에 추가 (중복 체크용 set 활용)
    set<int> check;
    for (const auto& subset : subsets) {
        for (int x : subset) {
            // 아직 등장하지 않은 숫자라면 튜플의 다음 원소임
            if (check.find(x) == check.end()) {
                check.insert(x);
                answer.push_back(x);
                break; 
            }
        }
    }

    return answer;
}