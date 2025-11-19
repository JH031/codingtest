from itertools import permutations

def solution(k, dungeons):
    max_count = 0
    nPr = permutations(dungeons,len(dungeons))
    
    for order in nPr:
        left = k
        count = 0
        
        for dungeon in order:
            min_left, cost = dungeon
            
            if min_left <= left:
                left -= cost
                count += 1
        max_count = max(max_count,count)
                
    return max_count