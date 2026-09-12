// 프로그래머스 72410 - 신규 아이디 추천 (2021 KAKAO BLIND RECRUITMENT, Lv1)
// https://school.programmers.co.kr/learn/courses/30/lessons/72410

#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string s;
    // 1·2단계: 소문자화 + 허용 문자(알파벳 소문자, 숫자, '-', '_', '.')만 남기기
    for (char c : new_id) {
        c = tolower(c);
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||
            c == '-' || c == '_' || c == '.')
            s += c;
    }

    // 3단계: 연속된 '.' → 하나로
    string t;
    for (char c : s) {
        if (c == '.' && !t.empty() && t.back() == '.')
            continue;
        t += c;
    }

    // 4단계: 앞뒤 '.' 제거
    if (!t.empty() && t.front() == '.')
        t.erase(t.begin());
    if (!t.empty() && t.back() == '.')
        t.pop_back();

    // 5단계: 빈 문자열이면 "a"
    if (t.empty())
        t = "a";

    // 6단계: 16자 이상이면 15자로 자르고, 끝이 '.'이면 제거
    if (t.size() >= 16)
        t = t.substr(0, 15);
    if (t.back() == '.')
        t.pop_back();

    // 7단계: 3자 미만이면 마지막 문자를 3자가 될 때까지 반복
    while (t.size() < 3)
        t += t.back();

    return t;
}
