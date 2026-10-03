// 프로그래머스 17682 - 다트 게임 (구현/문자열)
// https://school.programmers.co.kr/learn/courses/30/lessons/17682
//
// 처음 풀이(던지기 단위로 쪼갠 뒤 계산)를 그대로 두고, 두 군데만 고침:
//   [변경1] for (char d : ...) → for (int i ...) 인덱스 접근. 다음 글자를 봐야 "10"을 정확히 판별 가능
//   [변경2] val / ex_val / ex_a 변수 대신 vector<int> scores에 점수 저장.
//           *, #가 나오면 저장된 값 자체를 고쳐서, 다음 *가 옵션까지 반영된 직전 점수를 두 배로 만들게 함

#include <string>
#include <vector>
#include <cctype>
using namespace std;

int solution(string dartResult) {
    // ---- 1단계: 던지기 단위로 쪼개기 ("1S2D*3T" → {"1S"}, {"2D*"}, {"3T"}) ----
    vector<vector<char>> darts;
    vector<char> dart;

    for (int i = 0; i < dartResult.size(); i++) {   // [변경1]
        char d = dartResult[i];

        if (isdigit(d) && dart.size() > 0) {   // 새 숫자 = 새 던지기 시작 → 지금까지 모은 걸 저장
            darts.push_back(dart);
            dart = {};
        }
        dart.push_back(d);

        if (d == '1' && i + 1 < dartResult.size() && dartResult[i+1] == '0') {   // [변경1] "10"은 바로 다음 글자로 판별
            dart.push_back('0');
            i++;   // '0'은 이미 넣었으니 건너뛰기
        }
    }
    darts.push_back(dart);   // 마지막 던지기

    // ---- 2단계: 던지기마다 점수 계산 ----
    vector<int> scores;   // [변경2]

    for (vector<char> dar : darts) {
        int a = 0;
        for (int j = 0; j < dar.size(); j++) {   // [변경1]
            char d = dar[j];

            if (isdigit(d)) {
                if (d == '1' && j + 1 < dar.size() && dar[j+1] == '0') { a = 10; j++; }
                else a = d - '0';
            }
            else if (d == 'S') scores.push_back(a);
            else if (d == 'D') scores.push_back(a * a);
            else if (d == 'T') scores.push_back(a * a * a);
            else if (d == '*') {                                // [변경2]
                scores.back() *= 2;                             // 이번 점수 ×2
                if (scores.size() >= 2)
                    scores[scores.size() - 2] *= 2;             // 직전 점수 ×2 (첫 던지기면 직전 없음)
            }
            else if (d == '#') {                                // [변경2]
                scores.back() *= -1;                            // 이번 점수 음수로 "바꿔둠"
            }
        }
    }

    int answer = 0;
    for (int s : scores) answer += s;
    return answer;
}
