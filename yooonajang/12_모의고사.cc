// 프로그래머스 42840 - 모의고사 (완전탐색/패턴 비교)
// https://school.programmers.co.kr/learn/courses/30/lessons/42840

#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> f = {1,2,3,4,5};
    vector<int> s = {2,1,2,3,2,4,2,5};
    vector<int> t = {3,3,1,1,2,2,4,4,5,5};

    int f_c = 0, s_c = 0, t_c = 0;

    for (int i = 0; i < (int)answers.size(); i++) {
        int f_i = f[i % f.size()];   // 패턴 길이를 넘어가면 처음부터 반복
        int s_i = s[i % s.size()];
        int t_i = t[i % t.size()];
        int a_i = answers[i];

        if (f_i == a_i) f_c += 1;
        if (s_i == a_i) s_c += 1;
        if (t_i == a_i) t_c += 1;
    }

    vector<int> score = {f_c, s_c, t_c};
    int me = *max_element(score.begin(), score.end());   // 최댓값 (max_element는 위치를 주므로 * 필요)

    for (int i = 0; i < 3; i++) {
        if (score[i] == me) {
            answer.push_back(i + 1);   // 공동 1등 전부 수집 (max_element만으론 하나밖에 못 찾음)
        }
    }
    return answer;   // i가 0→1→2 순서로 도므로 이미 오름차순
}
