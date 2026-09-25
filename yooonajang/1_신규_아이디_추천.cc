// 프로그래머스 72410 - 신규 아이디 추천 (카카오 2021)
// https://school.programmers.co.kr/learn/courses/30/lessons/72410
//
// [문제 요약] new_id를 아래 7단계 규칙으로 바꿔서 최종 아이디를 return.
//
// 파이썬 하던 사람을 위한 포인트:
//  - 파이썬 str은 "불변"이라 매번 새 문자열을 만들지만,
//    C++ string은 s += c, s.pop_back() 처럼 "직접 수정"이 가능하다. (훨씬 편함)
//  - 문자 하나는 파이썬에선 길이1 문자열이지만, C++에선 char 타입이고 작은따옴표 'a' 를 쓴다.

#include <string>
#include <cctype>   // tolower(소문자변환), isalnum(영문자 or 숫자인지)
using namespace std;

string solution(string new_id) {
    string s;

    // 1단계 + 2단계: 대문자는 소문자로, 그리고 [소문자/숫자/ - _ . ]만 남긴다.
    // 파이썬: ''.join(c for c in new_id.lower() if c.isalnum() or c in '-_.')
    for (char c : new_id) {          // 파이썬의 for c in new_id 와 똑같다
        c = tolower(c);              // 대문자면 소문자로 (원래 소문자/기호면 그대로 둠)
        if (isalnum(c) || c == '-' || c == '_' || c == '.') {
            s += c;                  // 조건 통과한 문자만 이어붙이기
        }
    }

    // 3단계: 마침표(.)가 2번 이상 연속되면 하나로 합친다.
    // "바로 앞 글자가 이미 .인데 지금도 .이면 → 건너뛴다" 로직.
    string t;
    for (char c : s) {
        if (c == '.' && !t.empty() && t.back() == '.') continue;  // 연속된 . 은 스킵
        t += c;
    }
    s = t;

    // 4단계: 맨 앞/맨 뒤에 있는 마침표를 제거한다.
    if (!s.empty() && s.front() == '.') s.erase(s.begin()); // 맨 앞 글자 삭제
    if (!s.empty() && s.back()  == '.') s.pop_back();       // 맨 뒤 글자 삭제

    // 5단계: 결과가 빈 문자열이면 "a"를 넣는다.
    if (s.empty()) s = "a";

    // 6단계: 16자 이상이면 앞 15자만 남기고, 자른 뒤 끝이 .이면 그것도 제거.
    if (s.size() >= 16) {
        s = s.substr(0, 15);                       // 인덱스 0부터 15개 (파이썬 s[:15])
        if (s.back() == '.') s.pop_back();
    }

    // 7단계: 2자 이하이면 마지막 문자를 반복해서 3자로 만든다.
    while (s.size() <= 2) {
        s += s.back();     // 마지막 글자를 계속 덧붙임
    }

    return s;
}
