// 프로그래머스 64061 - 크레인 인형뽑기 게임 (구현 + 스택)
// https://school.programmers.co.kr/learn/courses/30/lessons/64061

#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;

    for (int m : moves) {
        int n = m - 1;
        for (vector<int>& v : board) {   // 참조(&)로 받아야 board 원본이 실제로 바뀜
            if (v[n] != 0) {
                int p = v[n];
                st.push(p);
                v[n] = 0;
                break;   // 그 열에서 가장 위(첫 번째로 찾은 것) 하나만 뽑고 종료
            }
        }

        if (st.size() >= 2) {
            int x = st.top();
            st.pop();
            int y = st.top();

            if (x == y) {
                st.pop();       // 같으면 둘 다 제거 (터짐)
                answer += 2;
            } else {
                st.push(x);     // 다르면 되돌리기
            }
        }
    }
    return answer;
}
