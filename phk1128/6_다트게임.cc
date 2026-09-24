#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    vector<int> scores;
    int i = 0;

    while (i < dartResult.size()) {
        int score = dartResult[i++] - '0';

        if (score == 1 && i < dartResult.size() && dartResult[i] == '0') {
            score = 10;
            i++;
        }

        char bonus = dartResult[i++];

        if (bonus == 'D') score *= score;
        if (bonus == 'T') score *= score * score;

        scores.push_back(score);

        if (i < dartResult.size() && dartResult[i] == '*') {
            scores.back() *= 2;
            if (scores.size() > 1) {
                scores[scores.size() - 2] *= 2;
            }
            i++;
        } else if (i < dartResult.size() && dartResult[i] == '#') {
            scores.back() *= -1;
            i++;
        }
    }

    int answer = 0;

    for (int score : scores) {
        answer += score;
    }

    return answer;
}