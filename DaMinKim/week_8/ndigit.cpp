#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 숫자를 n진법 문자열로 변환하는 함수
string convert(int num, int n) {
    if (num == 0) return "0";
    
    string result = "";
    string digits = "0123456789ABCDEF"; // 10~15를 A~F로 매핑
    
    while (num > 0) {
        result += digits[num % n];
        num /= n;
    }
    
    // 나머지를 역순으로 더했으므로 뒤집어줌
    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string total_str = "";
    
    // 1. 모든 사람이 말할 전체 문자열 생성
    // 튜브가 t개를 구하려면 전체 문자열 길이는 최소 t * m 이상이어야 함
    int num = 0;
    while (total_str.length() < t * m) {
        total_str += convert(num, n);
        num++;
    }
    
    // 2. 전체 문자열에서 튜브의 순서(p)에 맞는 문자만 추출
    // 순서 p는 인덱스로는 p-1, 다음 순서는 m만큼 더함
    for (int i = 0; i < t; i++) {
        answer += total_str[(p - 1) + (i * m)];
    }
    
    return answer;
}