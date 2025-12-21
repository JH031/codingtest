def solution(s):
    answer = []
    
    s = s[2:-2].split("},{")
    
    data = []
    for n in s:
        num_list = list(map(int, n.split(',')))
        data.append(num_list)
        
    data.sort(key=lambda x: len(x))
    
    for subset in data:
        for number in subset:
            if number not in answer:
                answer.append(number)
                break 
                
    return answer