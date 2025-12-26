from collections import Counter

def solution(str1, str2):
    # 1. 두 글자씩 끊어서 다중집합 만들기 
    arr1 = [str1[i:i+2].lower() for i in range(len(str1)-1) if str1[i:i+2].isalpha()]
    arr2 = [str2[i:i+2].lower() for i in range(len(str2)-1) if str2[i:i+2].isalpha()]

    # 2. Counter 객체 생성
    c1 = Counter(arr1)
    c2 = Counter(arr2)
    
    # 교집합 개수 구하기
    inter = sum((c1 & c2).values())
    
    # 합집합 개수 구하기
    union = sum((c1 | c2).values())

    # 4. 자카드 유사도 계산
    if union == 0:
        return 65536
    
    return int((inter / union) * 65536)