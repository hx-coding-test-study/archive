// 프로그래머스 42889 - 실패율 (구현 + 정렬)
// https://school.programmers.co.kr/learn/courses/30/lessons/42889

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double,double>> fail;
    double total_users = stages.size();

    for (int i = 1; i <= N; i++) {
        double users = 0;
        for (int st : stages) {
            if (i == st) users += 1.0;
        }

        double fail_percent;
        if (total_users == 0) fail_percent = 0;          // 도달한 사람 0명 → 0/0 방지
        else fail_percent = users / total_users;

        fail.push_back({fail_percent, -i});
        total_users -= users;
    }

    sort(fail.rbegin(), fail.rend());
    for (pair<double, double> p : fail) answer.push_back(-p.second);

    return answer;
}
