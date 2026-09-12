#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int height = board.size();
    stack<int> st;
    for (int move : moves) {
        int r = 0;
        while (r < height) {
            if (board[r][move - 1] != 0) {
                int doll = board[r][move - 1];
                if (st.empty()) {
                    st.push(doll);
                } else {
                    if (st.top() == doll) {
                        st.pop();
                        answer += 2;
                    } else {
                        st.push(doll);
                    }
                }
                board[r][move - 1] = 0;
                break;
            } else {
                r++;
            }
        }
    }
    return answer;
}