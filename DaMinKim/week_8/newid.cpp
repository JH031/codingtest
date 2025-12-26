#include <string>
#include <vector>
#include <algorithm> // tolower 사용을 위해 포함

using namespace std;

string solution(string new_id) {
    string answer = "";

    // 1단계: 모든 대문자를 소문자로 치환
    for (int i = 0; i < new_id.length(); i++) {
        new_id[i] = tolower(new_id[i]);
    }

    // 2단계: 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자 제거
    for (char c : new_id) {
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || 
            c == '-' || c == '_' || c == '.') {
            answer += c;
        }
    }

    // 3단계: 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
    // ".. " 문자열을 찾아서 없을 때까지 "."으로 바꿉니다.
    while (answer.find("..") != string::npos) {
        answer.replace(answer.find(".."), 2, ".");
    }

    // 4단계: 마침표(.)가 처음이나 끝에 위치한다면 제거
    if (!answer.empty() && answer.front() == '.') {
        answer.erase(0, 1);
    }
    if (!answer.empty() && answer.back() == '.') {
        answer.pop_back();
    }

    // 5단계: 빈 문자열이라면, "a"를 대입
    if (answer.empty()) {
        answer = "a";
    }

    // 6단계: 길이가 16자 이상이면, 첫 15개 문자만 남기기
    if (answer.length() >= 16) {
        answer = answer.substr(0, 15);
        // 제거 후 끝에 마침표(.)가 위치한다면 제거
        if (answer.back() == '.') {
            answer.pop_back();
        }
    }

    // 7단계: 길이가 2자 이하라면, 마지막 문자를 길이가 3이 될 때까지 반복
    while (answer.length() <= 2) {
        answer += answer.back();
    }

    return answer;
}