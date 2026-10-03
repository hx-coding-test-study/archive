// 프로그래머스 389478 - 택배 상자 꺼내기 (구현 + 스택)
// https://school.programmers.co.kr/learn/courses/30/lessons/389478

#include <vector>
#include <stack>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    vector<stack<int>> stacks(w);

    for (int i = 0; i < n; i++) {
        int idx = i % w;   // 나머지 = 몇 번째 열인지
        int q = i / w;     // 몫 = 몇 번째 줄인지
        int val = i + 1;

        if (q % 2 == 0) {
            stacks[idx].push(val);        // 짝수 줄: 왼쪽→오른쪽
        } else {
            stacks[w - idx - 1].push(val); // 홀수 줄: 오른쪽→왼쪽 (지그재그)
            // 주의: w를 그대로 써야 함. 숫자 하드코딩하면 heap-buffer-overflow로 core dumped 남
        }
    }

    for (stack<int> s : stacks) {
        int cnt = 0;
        while (!s.empty()) {
            int v = s.top();
            if (v == num) {
                answer = cnt + 1;   // num까지 포함해서 몇 개 꺼내야 하는지
                break;
            }
            s.pop();
            cnt += 1;
        }
    }
    return answer;
}
