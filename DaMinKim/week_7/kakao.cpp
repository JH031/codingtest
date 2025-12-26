#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 스테이지 번호와 실패율을 함께 저장하기 위한 구조체
struct Stage {
    int id;
    double failureRate;
};

// 정렬 기준 함수
bool compareStages(const Stage& a, const Stage& b) {
    if (a.failureRate == b.failureRate) {
        return a.id < b.id; // 실패율이 같으면 작은 번호가 우선
    }
    return a.failureRate > b.failureRate; // 실패율 내림차순
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<Stage> v;
    
    // 1. 각 스테이지에 머물러 있는 사람의 수 카운트 (N+1은 올클리어이므로 N+2 크기)
    vector<int> count(N + 2, 0);
    for (int s : stages) {
        count[s]++;
    }

    double totalPlayers = stages.size(); // 스테이지에 도달한 총 유저 수

    // 2. 각 스테이지별 실패율 계산
    for (int i = 1; i <= N; i++) {
        if (totalPlayers == 0) {
            // 도달한 유저가 없으면 실패율은 0
            v.push_back({i, 0.0});
        } else {
            double rate = (double)count[i] / totalPlayers;
            v.push_back({i, rate});
            // 다음 스테이지 도달 유저 수 = 현재 도달 유저 수 - 현재 스테이지 실패자 수
            totalPlayers -= count[i];
        }
    }

    // 3. 정렬 조건에 맞춰 정렬
    sort(v.begin(), v.end(), compareStages);

    // 4. 결과값(스테이지 번호)만 answer에 담기
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(v[i].id);
    }

    return answer;
}