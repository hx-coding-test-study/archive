// 프로그래머스 64061 - 크레인 인형뽑기 게임
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int n = board.size();

    vector<int> top(n, 0);                       // top[c] = c열에서 다음에 뽑을 인형의 행
    for (int c = 0; c < n; c++) {
        int r = 0;
        while (r < n && board[r][c] == 0) r++;   // 위에서부터 빈 칸(0) 건너뛰기
        top[c] = r;                              // r == n 이면 빈 열
    }

    vector<int> basket;                          // back()이 바구니 맨 위
    int answer = 0;

    for (int m : moves) {
        int c = m - 1;                           // moves는 1번부터 세므로 0부터 세는 열 인덱스로 변환
        if (top[c] >= n) continue;               // 빈 열이면 아무 일도 없음

        int doll = board[top[c]][c];
        top[c]++;

        if (!basket.empty() && basket.back() == doll) {
            basket.pop_back();
            answer += 2;                         // 두 개가 함께 터짐
        } else {
            basket.push_back(doll);
        }
    }

    return answer;
}
