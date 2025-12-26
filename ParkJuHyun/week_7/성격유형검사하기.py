def solution(survey, choices):
    answer = ''
    
    scores = {"R":0, "T":0, "C":0, "F":0, "J":0, "M":0, "A":0, "N":0}
    
    for i in range(len(survey)):
        disagree_char = survey[i][0]
        agree_char = survey[i][1]
        choice = choices[i]
        
        if choice== 4:
            continue
        elif choice <= 3:
             scores[disagree_char] += (4-choice)
        else:
            scores[agree_char] += (choice - 4)
    type = [("R", "T"), ("C", "F"), ("J", "M"), ("A", "N")]
    
    for first, second in type:
        if scores[first] >= scores[second]:
            answer += first
        else:
            answer += second
            
    return answer