from collections import Counter

def solution(str1, str2):
    str1 = str1.upper()
    str2 = str2.upper()
    
    lst1 = []
    lst2 = []
    
    for i in range(len(str1)-1):
        token = str1[i:i+2]
        if token.isalpha():
            lst1.append(token)
            
    for i in range(len(str2)-1):
        token = str2[i:i+2]
        if token.isalpha():
            lst2.append(token)
    c1 = Counter(lst1)
    c2 = Counter(lst2)
    
    tokens = set(c1.keys()) | set(c2.keys())
    
    intersection = 0
    union = 0
    
    for token in tokens:
        intersection += min(c1[token],c2[token])
        union += max(c1[token],c2[token])

    if union == 0:
        return 65536
    
    return int((intersection / union) *65536)