#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    // 1. 캐시 크기가 0인 경우 모든 경우가 miss
    if (cacheSize == 0) return cities.size() * 5;

    for (string city : cities) {
        // 대소문자 구분을 하지 않으므로 소문자로 통일
        for (int i = 0; i < city.length(); i++) {
            city[i] = tolower(city[i]);
        }

        // 2. 캐시에 해당 도시가 있는지 확인 (Cache Hit/Miss 확인)
        auto it = find(cache.begin(), cache.end(), city);

        if (it != cache.end()) {
            // Case: Cache Hit
            answer += 1;
            // 해당 데이터를 제거하고 가장 최신 위치(뒤쪽)로 다시 추가
            cache.erase(it);
            cache.push_back(city);
        } else {
            // Case: Cache Miss
            answer += 5;
            // 캐시가 가득 찼다면 가장 오래된 것(앞쪽) 제거
            if (cache.size() >= cacheSize) {
                cache.erase(cache.begin());
            }
            // 새로운 데이터를 캐시에 추가
            cache.push_back(city);
        }
    }

    return answer;
}