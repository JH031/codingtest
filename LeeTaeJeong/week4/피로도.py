from itertools import permutations # 순열 라이브러리 임포트
def solution(k, dungeons):
    answer = -1
    row = [] # 던전 인덱스 담을 리스트
    for i in range(len(dungeons)): # 던전 개수만큼 인덱스 추가
        row.append(i) 
        
    row_orders = list(permutations(row)) # 던전 인덱스 순열 생성
    for r in row_orders: # 각 던전 순열에 대해
        need, count = k, 0 # 현재 피로도와 탐험한 던전 개수 초기화
        for index in r: # 던전 순열의 각 던전에 대해
            if need>= dungeons[index][0]: # 현재 피로도가 던전 최소 필요 피로도 이상이면
                need= need-dungeons[index][1] # 던전 탐험 후 피로도 갱신
                count+=1
            else:
                break
        if count > answer: # 최대 탐험 던전 수 갱신
            answer = count  
        
    return answer