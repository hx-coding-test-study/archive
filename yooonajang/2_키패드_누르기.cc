// 프로그래머스 67256 - 키패드 누르기 (카카오 2020)
// https://school.programmers.co.kr/learn/courses/30/lessons/67256

#include <string>
#include <vector>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> left = {3, 0};   // 왼손 시작 위치 = '*'
    pair<int,int> right = {3, 2};  // 오른손 시작 위치 = '#'

    for (int n : numbers) {
        if (n == 0) n = 11;   // 0은 (3,1)이라 공식이 안 맞으므로, 11로 치환해서 공식 재사용

        int i = n - 1;
        int x = i / 3;   // 행
        int y = i % 3;   // 열

        int left_dis = abs(left.first - x) + abs(left.second - y);
        int right_dis = abs(right.first - x) + abs(right.second - y);

        if (n == 1 || n == 4 || n == 7) {
            left = {x, y};
            answer += 'L';
        }
        else if (n == 3 || n == 6 || n == 9) {
            right = {x, y};
            answer += 'R';
        }
        else if (left_dis < right_dis) {
            left = {x, y};
            answer += 'L';
        }
        else if (left_dis > right_dis) {
            right = {x, y};
            answer += 'R';
        }
        else {
            if (hand == "left") {
                left = {x, y};
                answer += 'L';
            } else {
                right = {x, y};
                answer += 'R';
            }
        }
    }
    return answer;
}
