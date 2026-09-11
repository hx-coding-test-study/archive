#include <string>
#include <vector>
#include <cmath>     // abs 사용
using namespace std;

// ─────────────────────
// 키패드 번호 n의 좌표를 {행, 열}로 반환
//
//   (0,0)1  (0,1)2  (0,2)3
//   (1,0)4  (1,1)5  (1,2)6
//   (2,0)7  (2,1)8  (2,2)9
//   (3,0)*  (3,1)0  (3,2)#
// ─────────────────────
pair<int, int> getPos(int n) {
    // 0은 맨 아랫줄 가운데. 아래 공식으로 안 나오는 예외라 직접 지정
    if (n == 0) return {3, 1};

    // 1~9를 n-1 해서 0~8로 만든 뒤 3칸씩 끊음
    // (n-1)/3 : 3개씩 묶었을 때 몇 번째 묶음인가 -> 행
    // (n-1)%3 : 그 묶음 안에서 몇 번째인가      -> 열
    return {(n - 1) / 3, (n - 1) % 3};
}

// ─────────────────────
// 두 좌표 a, b 사이의 거리 (맨해튼 거리)
// 대각선 이동이 없으므로 "세로 이동칸 + 가로 이동칸"
// abs로 절댓값을 씨우는 이유: 방향(위/아래)은 무의미하고
//                            몇 칸인지만 중요하기 때문
// ─────────────────────
int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first  - b.first)    // 행 차이 = 상하 이동 칸 수
         + abs(a.second - b.second);  // 열 차이 = 좌우 이동 칸 수
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    // 손의 현재 위치. 시작은 왼손 '*'(3,0), 오른손 '#'(3,2)
    pair<int, int> left  = {3, 0};
    pair<int, int> right = {3, 2};

    for (int num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            // 왼쪽 열 -> 무조건 왼손
            answer += 'L';
            left = getPos(num);          // 왼손 위치 갱신
        }
        else if (num == 3 || num == 6 || num == 9) {
            // 오른쪽 열 -> 무조건 오른손
            answer += 'R';
            right = getPos(num);         // 오른손 위치 갱신
        }
        else {
            // 가운데 열(2,5,8,0) -> 거리를 재서 가까운 손으로
            pair<int, int> target = getPos(num);
            int L = dist(left,  target); // 왼손에서 목적지까지 거리
            int R = dist(right, target); // 오른손에서 목적지까지 거리

            if (L < R) {                 // 왼손이 더 가까움
                answer += 'L';
                left = target;
            }
            else if (R < L) {            // 오른손이 더 가까움
                answer += 'R';
                right = target;
            }
            else {                       // 거리가 같음 -> 주로 쓰는 손
                if (hand == "left") {
                    answer += 'L';
                    left = target;
                } else {
                    answer += 'R';
                    right = target;
                }
            }
        }
    }

    return answer;
}
