#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* survey[], size_t survey_len, int choices[], size_t choices_len) {
    // 성격 유형 4글자 + 널 문자를 위한 5바이트 할당
    char* answer = (char*)malloc(sizeof(char) * 5);
    
    // 알파벳 'A'~'Z' 점수를 저장할 배열 (0으로 초기화)
    int score[26] = {0, };

    // 1. 점수 계산 로직
    for (size_t i = 0; i < survey_len; i++) {
        int choice = choices[i];
        
        if (choice < 4) {
            // 비동의 계열: survey[i][0] 성격 유형이 점수를 얻음
            score[survey[i][0] - 'A'] += (4 - choice);
        } else if (choice > 4) {
            // 동의 계열: survey[i][1] 성격 유형이 점수를 얻음
            score[survey[i][1] - 'A'] += (choice - 4);
        }
    }

    // 2. 지표별 성격 유형 결정
    // 1번 지표: R vs T
    answer[0] = (score['R' - 'A'] >= score['T' - 'A']) ? 'R' : 'T';
    
    // 2번 지표: C vs F
    answer[1] = (score['C' - 'A'] >= score['F' - 'A']) ? 'C' : 'F';
    
    // 3번 지표: J vs M
    answer[2] = (score['J' - 'A'] >= score['M' - 'A']) ? 'J' : 'M';
    
    // 4번 지표: A vs N
    answer[3] = (score['A' - 'A'] >= score['N' - 'A']) ? 'A' : 'N';
    
    // 문자열 끝을 알리는 널 문자 추가
    answer[4] = '\0';

    return answer;
}