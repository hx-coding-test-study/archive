// 프로그래머스 87946 - 피로도 (완전탐색/순열)
// https://school.programmers.co.kr/learn/courses/30/lessons/87946

#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int k_ = k;   // 매 순열마다 체력을 원래대로 리셋하려고 저장

    sort(dungeons.begin(), dungeons.end());   // next_permutation 쓰려면 먼저 정렬

    do {
        int cnt = 0;
        k = k_;
        for (vector<int> d : dungeons) {
            if (k >= d[0]) {   // 입장 가능하면 들어감
                k -= d[1];
                cnt += 1;
            }
            // 입장 불가능해도 멈추지 않고 다음 던전으로 계속 진행
        }
        answer = max(answer, cnt);
    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}
