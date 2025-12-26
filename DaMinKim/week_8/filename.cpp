#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 파일의 정보를 담을 구조체
struct FileInfo {
    string origin;  // 원래 파일명
    string head;    // 소문자로 변환된 HEAD
    int number;     // 숫자로 변환된 NUMBER
};

// 정렬 기준을 정의하는 함수
bool compare(const FileInfo& a, const FileInfo& b) {
    // 1. HEAD 기준 사전 순 정렬
    if (a.head != b.head) {
        return a.head < b.head;
    }
    // 2. HEAD가 같다면 NUMBER 기준 오름차순 정렬
    return a.number < b.number;
    // 3. 둘 다 같다면 stable_sort가 원래 순서를 보장함
}

vector<string> solution(vector<string> files) {
    vector<FileInfo> info;

    for (const string& file : files) {
        int i = 0;
        string h = "";
        string n = "";

        // 1. HEAD 추출 (숫자가 나오기 전까지)
        while (i < file.length() && !isdigit(file[i])) {
            h += tolower(file[i]); // 비교를 위해 소문자로 저장
            i++;
        }

        // 2. NUMBER 추출 (최대 5글자의 숫자)
        while (i < file.length() && isdigit(file[i]) && n.length() < 5) {
            n += file[i];
            i++;
        }

        info.push_back({file, h, stoi(n)});
    }

    // 조건에 따라 안정 정렬 수행
    stable_sort(info.begin(), info.end(), compare);

    vector<string> answer;
    for (const auto& f : info) {
        answer.push_back(f.origin);
    }

    return answer;
}