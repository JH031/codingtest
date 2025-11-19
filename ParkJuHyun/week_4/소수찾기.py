from itertools import permutations
import math

def is_prime_number(x):

    if x<2:
        return False
    
    for i in range(2,int(math.sqrt(x))+1):
        if x % i == 0:
            return False
    return True

def solution(numbers):
    count = 0
    num = []
    
    for i in numbers:
        num.append(i)
        
    length = len(num) 
    unique_numbers = set()
    
    for i in range(1, length + 1): 
        nPr = permutations(num, i)
        
        for order in nPr:
            result = "".join(order)
            unique_numbers.add(int(result))
    
    for n in unique_numbers:
        if is_prime_number(n):
            count += 1
            
    return count