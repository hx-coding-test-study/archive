#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> basket(900);
    int ptr = 0;
    int n = board[0].size();
    int answer = 0;
    // [0,0,0,0,0]
    // [0,0,1,0,3]
    // [0,2,5,0,1]
    // [4,2,4,4,2]
    // [3,5,1,3,1]
    for(int i=0; i<moves.size(); i++) {
        int m = moves[i] - 1;
        for(int j=0; j<n; j++) {
            if(board[j][m] > 0) {
                basket[ptr] = board[j][m];
                board[j][m] = 0;
                // std::cout << "in " << m << " " << basket[ptr] << std::endl;
                ptr = ptr + 1;
                break;
            }
        }
        
        if(ptr > 1) {
            if(basket[ptr-1] == basket[ptr-2]) {
                std::cout << "out" << basket[ptr-1] << basket[ptr-2] << std::endl;
                answer = answer + 2;
                basket[ptr-1] = 0;
                basket[ptr-2] = 0;
                ptr = ptr - 2;
            }
        }
    }
    
    return answer;
}
