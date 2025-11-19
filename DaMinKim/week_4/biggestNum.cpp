#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 사용자 정의 비교 함수
bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> strs;
    for (int num : numbers)
        strs.push_back(to_string(num));

    // 핵심: "문자열 이어붙이기 결과"를 기준으로 내림차순 정렬
    sort(strs.begin(), strs.end(), compare);

    // 모든 원소 이어붙이기
    string answer = "";
    for (string s : strs)
        answer += s;

    // "0000..." 같은 경우 처리 → "0"만 남기기
    if (answer[0] == '0') return "0";

    return answer;
}

int main() {
    int n;
    cout << "숫자 개수를 입력하세요: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "숫자들을 입력하세요: ";
    for (int i = 0; i < n; i++) cin >> numbers[i];

    string result = solution(numbers);
    cout << "가장 큰 수: " << result << endl;

    return 0;
}
