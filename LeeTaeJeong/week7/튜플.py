def solution(s):
    answer = []
    
    # 문자열 파싱
    s_list = s[2:-2].split("},{")
    
    # 정렬
    s_list.sort(key=len)
    
    # 원소 추출
    for st in s_list:
        # 문자열을 ','로 나누고 숫자로 변환하여 리스트로 만듦
        numbers = list(map(int, st.split(',')))
        
        for num in numbers:
            # answer에 없는 숫자만 추가
            if num not in answer:
                answer.append(num)
                
    return answer