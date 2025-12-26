from collections import deque

def solution(cacheSize, cities):
    # 캐시 크기가 0인 경우 모든 도시가 Cache Miss이므로 바로 계산해서 반환
    if cacheSize == 0:
        return len(cities) * 5
    
    answer = 0
    cache = deque(maxlen=cacheSize) # maxlen을 설정하면 꽉 찼을 때 자동으로 오래된 데이터가 밀려남
    
    for city in cities:
        # 대소문자 구분 없이 처리하기 위해 소문자로 변환
        city = city.lower()
        
        if city in cache:
            # Cache Hit (실행시간 +1)
            answer += 1
            # LRU 알고리즘: 사용된 데이터는 가장 맨 뒤로 이동해야 함
            cache.remove(city)
            cache.append(city)
        else:
            # Cache Miss (실행시간 +5)
            answer += 5
            # 캐시에 추가 
            cache.append(city)
            
    return answer