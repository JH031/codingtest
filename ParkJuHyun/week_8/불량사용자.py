from itertools import permutations

def is_match(user, banned):
    if len(user) != len(banned):
        return False
    
    for u, b in zip(user, banned):
        if b != '*' and u != b:
            return False
            
    return True

def solution(user_id, banned_id):
    result_set = set()
    
    for perm in permutations(user_id, len(banned_id)):
        match = True
        
        for i in range(len(banned_id)):
            if not is_match(perm[i], banned_id[i]):
                match = False
                break
        
        if match:
            result_set.add(tuple(sorted(perm)))
            
    return len(result_set)