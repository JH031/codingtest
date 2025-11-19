import math
from itertools import permutations

def is_prime(n): #소수인지 판별하는 함수
    # 0과 1은 소수가 아님
    if n < 2:
        return False
    
    # 2부터 n의 제곱근까지 나누어보며 확인
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0: # 나누어 떨어지는 수가 있다면
            return False # 소수가 아님
    
    # 모두 통과하면 소수
    return True

def solution(numbers):
    # 고유한 소수를 저장하기 위한 set
    prime_set = set()
    
    # numbers 문자열을 list로 변환
    num_list = list(numbers)
    
    # 1개부터 numbers의 길이만큼의 모든 조합을 확인
    for k in range(1, len(num_list) + 1):
        
        # 길이가 k인 모든 순열 생성 
        for perm in permutations(num_list, k):
            
            #  튜플을 문자열로 합친 후 정수로 변환
            num = int("".join(perm))
            
            # 이 숫자가 소수인지 판별
            if is_prime(num):
                # 소수라면 set에 추가
                prime_set.add(num)
                
    # 고유한 소수의 개수를 반환
    return len(prime_set)