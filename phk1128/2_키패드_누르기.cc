#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int getDst(int number1, int number2) {
      int mapView[4][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {-1,0,-2}
    };
    int pos1[2];
    int pos2[2];
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 3; c++) {
            if (mapView[r][c] == number1) {
                pos1[0] = r;
                pos1[1] = c;
            }
            if (mapView[r][c] == number2) {
                pos2[0] = r;
                pos2[1] = c;
            }
        }
    }
    return abs(pos1[0] - pos2[0]) + abs(pos1[1] - pos2[1]);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
  
    vector<int> left = {1,4,7};
    vector<int> right = {3,6,9}; 
    
    int leftHand = -1;
    int rightHand = -2;
    for (int i = 0; i < numbers.size(); i++) {
        int number = numbers[i];
        if (find(left.begin(), left.end(), number) != left.end()) {
            answer += 'L';
            leftHand = number;
            continue;
        }
        if (find(right.begin(), right.end(), number) != right.end()) {
            answer += 'R';
            rightHand = number;
            continue;
        }

        int leftDst = getDst(leftHand, number);
        int rightDst = getDst(rightHand, number);

        if (leftDst < rightDst) {
            answer += 'L';
            leftHand = number;
            continue;
        }

        if (leftDst > rightDst) {
            answer += 'R';
            rightHand = number;
            continue;
        }

        if (hand == "left") {
            answer += 'L';
            leftHand = number;
            continue;
        }

        if (hand == "right") {
            answer += 'R';
            rightHand = number;
            continue;
        }

    }
    return answer;
}