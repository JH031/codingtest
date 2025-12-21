def solution(N, stages):
    failure_rates = []
    counting =[]
    
    for i in range(1,N+1):
        counting.append(stages.count(i))
        
    total_player = len(stages)
    
    for i in range(1,N+1):
        if total_player == 0:
            fail_rate = 0
        else:
            fail_rate = counting[i-1] / total_player
        failure_rates.append((i,fail_rate))
        total_player -= counting[i-1]
        
    failure_rates.sort(key=lambda x:(-x[1],x[0]))
    return [stage[0] for stage in failure_rates]