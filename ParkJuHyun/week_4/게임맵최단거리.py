from collections import deque

def solution(maps):
    answer = 0
    raw = [-1, 1, 0, 0]
    col = [0, 0, -1, 1]
    
    def bfs(x, y):
        queue = deque()
        queue.append((x, y))
        
        while queue:
            x, y = queue.popleft()
            
            for i in range(4):
                nr = x + raw[i]
                nc = y + col[i]
                
                if nr < 0 or nr >= len(maps) or nc < 0 or nc >= len(maps[0]): continue
                
                if maps[nr][nc] == 0: continue
                if maps[nr][nc] == 1:
                    maps[nr][nc] = maps[x][y] + 1
                    queue.append((nr,nc))
        return maps[len(maps)-1][len(maps[0])-1]
    
    answer = bfs(0,0)
    if answer == 1: return -1
    else: return answer