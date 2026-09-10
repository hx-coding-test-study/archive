#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int curr_right = 12;
int curr_left = 10;

int getDistance(int curr, int num) {
  if (num == 0)
    num += 11;
  if (curr == 0)
    curr += 11;

  int ansR = (num - 1) / 3;
  int ansC = (num - 1) % 3;

  int currR = (curr - 1) / 3;
  int currC = (curr - 1) % 3;

  return abs(ansR - currR) + abs(ansC - currC);
}

string solution(vector<int> numbers, string hand) {
  string answer = "";

  for (int i = 0; i < (int)numbers.size(); i++) {
    if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
      curr_left = numbers[i];
      answer += "L";
    } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
      curr_right = numbers[i];
      answer += "R";
    } else {
      int left_dist = getDistance(curr_left, numbers[i]);
      int right_dist = getDistance(curr_right, numbers[i]);

      if (left_dist == right_dist) {
        if (hand == "right") {
          curr_right = numbers[i];
          answer += "R";
        } else {
          curr_left = numbers[i];
          answer += "L";
        }
      } else if (left_dist < right_dist) {
        curr_left = numbers[i];
        answer += "L";
      } else {
        curr_right = numbers[i];
        answer += "R";
      }
    }
  }

  return answer;
}