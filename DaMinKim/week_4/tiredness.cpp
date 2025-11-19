#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;

// DFS로 가능한 모든 탐험 순서를 시도
void dfs(int k, vector<vector<int>> &dungeons, vector<bool> &visited, int count) {
    answer = max(answer, count); // 최대 탐험 수 갱신

    for (int i = 0; i < dungeons.size(); i++) {
        int need = dungeons[i][0]; // 최소 필요 피로도
        int use = dungeons[i][1];  // 소모 피로도

        if (!visited[i] && k >= need) { // 탐험 가능한 경우
            visited[i] = true;
            dfs(k - use, dungeons, visited, count + 1);
            visited[i] = false; // 백트래킹
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    dfs(k, dungeons, visited, 0);
    return answer;
}

int main() {
    int k, n; // k: 현재 피로도, n: 던전 개수
    cout << "현재 피로도: ";
    cin >> k;

    cout << "던전의 개수: ";
    cin >> n;

    vector<vector<int>> dungeons(n, vector<int>(2));

    cout << "[최소 필요 피로도, 소모 피로도]:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        cin >> dungeons[i][0] >> dungeons[i][1];
    }

    int result = solution(k, dungeons);
    cout << "\n최대 던전 수: " << result << endl;

    return 0;
}
