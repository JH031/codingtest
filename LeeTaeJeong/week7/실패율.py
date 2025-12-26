def solution(N, stages):
    answer = []
    # 스테이지 번호와 실패율을 저장할 딕셔너리 (Key: 스테이지, Value: 실패율)
    fail_rates = {} 
    
    # 해당 스테이지에 도달한 플레이어 수 (초기값은 전체 사용자 수)
    people_arrived = len(stages)
    
    for i in range(1, N+1):
        if people_arrived != 0:
            # i번째 스테이지에 멈춰있는 사람 수 
            people_stuck = stages.count(i)
            
            # 실패율 계산
            fail_rate = people_stuck / people_arrived
            
            # 결과 저장
            fail_rates[i] = fail_rate
            
            # 다음 스테이지 도달자 수 갱신 (현재 스테이지에 멈춘 사람 제외)
            people_arrived -= people_stuck
        else:
            # 도달한 사람이 없는 경우 실패율은 0
            fail_rates[i] = 0

    # 자동으로 원래 순서(스테이지 번호가 작은 순)가 유지됩니다.
    sorted_stages = sorted(fail_rates.items(), key=lambda x: x[1], reverse=True)
    
    # 정렬된 결과에서 스테이지 번호만 추출
    for stage_info in sorted_stages:
        answer.append(stage_info[0])
        
    return answer