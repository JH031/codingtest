#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

// 소수 판별 함수
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    set<int> candidates; // 중복 제거용 (예: 011 → 11)
    sort(numbers.begin(), numbers.end()); // 순열 생성을 위해 정렬

    do {
        for (int len = 1; len <= numbers.size(); len++) {
            string sub = numbers.substr(0, len);
            int n = stoi(sub);
            candidates.insert(n);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    int count = 0;
    for (int num : candidates) {
        if (isPrime(num)) count++;
    }

    return count;
}

int main() {
    string numbers;
    cout << "num: ";
    cin >> numbers;

    int result = solution(numbers);
    cout << "소수 개수: " << result << endl;

    return 0;
}
