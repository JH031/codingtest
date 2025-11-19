from collections import deque

def solution(maps):
    # 맵의 크기 (n: 행, m: 열)
    n = len(maps)
    m = len(maps[0])
    
    # 거리(및 방문) 기록용 2차원 배열
    # -1은 아직 방문하지 않았음을 의미
    distance = [[-1] * m for _ in range(n)]
    
    # 큐(Queue)
    queue = deque()
    
    # 초기 설정: 시작점 (0, 0)을 큐에 추가하고 거리 1로 설정
    queue.append((0, 0))
    distance[0][0] = 1
    
    # 4방향 탐색을 위한 방향 벡터 (상, 하, 좌, 우)
    dr = [-1, 1, 0, 0]  # 행 (row) 변화
    dc = [0, 0, -1, 1]  # 열 (column) 변화
    
    # 탐색 시작 (BFS 루프)
    while queue:
        # 큐에서 현재 위치 (r, c)를 꺼냄
        r, c = queue.popleft()
        
        # 현재 위치에서 4방향을 확인
        for i in range(4):
            nr = r + dr[i]  # 다음 행
            nc = c + dc[i]  # 다음 열
            
            # 3가지 조건 검사
            # 조건 1: 맵의 경계 안에 있는가?
            if 0 <= nr < n and 0 <= nc < m:
                # 조건 2: 벽이 아닌가? 
                # 조건 3: 아직 방문한 적이 없는가? 
                if maps[nr][nc] == 1 and distance[nr][nc] == -1:
                    
                    # 다음 위치의 거리는 (현재 거리 + 1)
                    distance[nr][nc] = distance[r][c] + 1
                    # 큐에 다음 위치를 추가하여 나중에 탐색하도록 함
                    queue.append((nr, nc))
                    
    return distance[n-1][m-1]