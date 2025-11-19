#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 방향 벡터 (상, 하, 좌, 우)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> maps) {
    int n = maps.size();       // 행 (세로)
    int m = maps[0].size();    // 열 (가로)

    vector<vector<int>> dist(n, vector<int>(m, 0)); // 방문 여부 + 거리 저장
    queue<pair<int, int>> q;

    q.push({0, 0});
    dist[0][0] = 1; // 시작점 거리 = 1 (첫 칸 포함)

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 목표지점 도착 시 반환
        if (x == n - 1 && y == m - 1) return dist[x][y];

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 맵 범위 벗어나면 continue
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            // 벽이거나 이미 방문한 곳이면 continue
            if (maps[nx][ny] == 0 || dist[nx][ny] > 0) continue;

            dist[nx][ny] = dist[x][y] + 1; // 거리 갱신
            q.push({nx, ny});
        }
    }

    // 도착 불가 시
    return -1;
}

int main() {
    int n, m;
    cout << "맵의 행 크기를 입력하세요: ";
    cin >> n;
    cout << "맵의 열 크기를 입력하세요: ";
    cin >> m;

    vector<vector<int>> maps(n, vector<int>(m));
    cout << "맵 정보를 입력하세요 (0=벽, 1=길):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maps[i][j];
        }
    }

    int result = solution(maps);
    cout << "\n최단 이동 칸 수: " << result << endl;

    return 0;
}
