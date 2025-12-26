def solution(survey, choices):
    answer = ''
    scores = {'R': 0, 'T': 0, 'C': 0, 'F': 0, 'J': 0, 'M': 0, 'A': 0, 'N': 0}
    
    for i in range(len(survey)):
        type_disagree = survey[i][0] # 비동의 시 점수를 얻는 유형
        type_agree = survey[i][1]    # 동의 시 점수를 얻는 유형
        choice = choices[i]
        
        if choice < 4: 
            # 비동의
            scores[type_disagree] += (4 - choice)
        elif choice > 4: 
            # 동의
            scores[type_agree] += (choice - 4)
            
    indicators = [('R', 'T'), ('C', 'F'), ('J', 'M'), ('A', 'N')]
    
    for type1, type2 in indicators:
        # type1의 점수가 type2보다 크거나 같으면 type1 선택
        if scores[type1] >= scores[type2]:
            answer += type1
        else:
            answer += type2
            
    return answer