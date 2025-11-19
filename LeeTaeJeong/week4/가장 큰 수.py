def solution(numbers):
    # 모든 숫자를 문자열로 변환
    numbers_str = list(map(str, numbers))
    
    # 'x * 3'을 기준으로 내림차순 정렬
    # '3' -> '333', '30' -> '303030'
    # '333'과 '303030'을 비교하면 '333'이 더 큼 (문자열 비교)
    # 따라서 [3, 30] 순서가 됨
    numbers_str.sort(key=lambda x: x * 3, reverse=True)
    
    # 정렬된 문자열을 하나로 합침
    answer = "".join(numbers_str)
    
    # [0, 0, 0] -> '000'이 되는 예외 케이스 처리
    # '000'을 int로 바꾸면 0이 되고, 다시 str로 바꾸면 '0'이 됨
    return str(int(answer))

#### 테스트는 통과했으나 시간 초과로 실패한 풀이 ####
##실패 이유: 모든 순열을 구해서 가장 큰 수를 찾는 방식이기 때문에 시간 복잡도가 매우 높음.
from itertools import permutations
def solution(numbers):
    answer = ''
    mmax = 0 
    perm_num = permutations(numbers)
    for n in perm_num:
        num_str = "".join(map(str, n))
        num = int(num_str)
        mmax = max(num, mmax)
    answer = str(mmax)
    return answer