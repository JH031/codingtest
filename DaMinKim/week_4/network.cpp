#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &computers, vector<bool> &visited, int n) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        // 연결되어 있고, 아직 방문하지 않은 컴퓨터
        if (computers[node][i] == 1 && !visited[i]) {
            dfs(i, computers, visited, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    int networkCount = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, computers, visited, n);
            networkCount++; // 새로운 네트워크 발견
        }
    }

    return networkCount;
}

int main() {
    int n;
    cout << "컴퓨터 개수를 입력하세요: ";
    cin >> n;

    vector<vector<int>> computers(n, vector<int>(n));
    cout << "연결 정보를 입력하세요 (n x n 행렬, 1=연결, 0=비연결):" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> computers[i][j];
        }
    }

    int result = solution(n, computers);
    cout << "\n네트워크 개수: " << result << endl;

    return 0;
}
