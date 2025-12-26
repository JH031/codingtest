def solution(gems):
    n = len(set(gems))
    length = len(gems)
    
    answer = [0, length]
    
    start = 0
    end = 0
    
    gem_dict = {}
    
    while end < length:
        gem_dict[gems[end]] = gem_dict.get(gems[end], 0) + 1
        end += 1
        
        if len(gem_dict) == n:
            while start < end:
                if gem_dict[gems[start]] > 1:
                    gem_dict[gems[start]] -= 1
                    start += 1
                else:
                    break
            
            if (end - start) < (answer[1] - answer[0] + 1):
                answer = [start + 1, end]
                
    return answer