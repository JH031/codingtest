def solution(n, t, m, p):
    def convert(num, base):
        if num == 0:
            return "0"
        
        digits = "0123456789ABCDEF"
        result = ""
        while num > 0:
            result = digits[num % base] + result
            num //= base
        return result

    full_sequence = ""
    number = 0
    while len(full_sequence) < t * m:
        full_sequence += convert(number, n)
        number += 1
    
    answer = full_sequence[p-1::m][:t]
    
    return answer