#include <string>
#include <vector>

using namespace std;

int doll_cnt;

vector<int> V; // 숫자 저장 배열

void delete_same() {

  int size = (int)V.size();

  if (size >= 2) {
    if (V[size - 1] == V[size - 2]) {
      V.pop_back();
      V.pop_back();
      doll_cnt += 2;
    }
  } else {
    return;
  }
}

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;

  int size = (int)board.size();
  int move_cnt = (int)moves.size();

  // [1,5,3,5,1,2,1,4]

  for (int i = 0; i < move_cnt; i++) {
    int loc = moves[i] - 1;
    int start = 0;

    while (board[start][loc] == 0) {
      start++;
      if (start >= size) {
        break;
      }
    }

    if (start >= size)
      continue;

    V.push_back(board[start][loc]);
    board[start][loc] = 0;
    delete_same();
  }

  answer = doll_cnt;

  return answer;
}