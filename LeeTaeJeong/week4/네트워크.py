def solution(n, computers):
    answer = 0
    visited = [False] * n  # 각 컴퓨터의 방문 여부를 기록

    def dfs(node):
        # 하나의 네트워크를 모두 방문 처리하는 DFS 함수
        visited[node] = True  # 현재 컴퓨터 방문 처리
        
        # 현재 컴퓨터와 연결된 다른 모든 컴퓨터를 확인
        for neighbor in range(n):
            #  연결되어 있고 아직 방문하지 않았다면 
            if computers[node][neighbor] == 1 and not visited[neighbor]:
                dfs(neighbor)  # 재귀적으로 방문

    # 모든 컴퓨터를 순회
    for i in range(n):
        # 아직 방문하지 않은 컴퓨터가 있다면
        if not visited[i]:
            dfs(i)      # 이 컴퓨터와 연결된 모든 노드를 탐색
            answer += 1 # 새로운 네트워크를 발견했으므로 +1

    return answer