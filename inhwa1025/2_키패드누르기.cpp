#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l_prev = 10;
    int r_prev = 12;
    int l_dist = 100;
    int r_dist = 100;
    
    for(int i=0; i<numbers.size(); i++) {
        if(numbers[i]==0) {numbers[i]=11;}
        if(numbers[i]%3 == 1) {
            answer = answer + "L";
            l_prev = numbers[i];
        } else if(numbers[i]%3 == 0) {
            answer = answer + "R";
            r_prev = numbers[i];
        } else {
            if((l_prev%3 == 2) & (numbers[i]%3 == 2)) {
                l_dist = abs(numbers[i] - l_prev)/3;
            } else {
                l_dist = abs(numbers[i] - l_prev);
            }
            if((r_prev%3 == 0) & (numbers[i]%3 == 2)) {
                r_dist = abs(numbers[i] - r_prev + 2);
            } else if((r_prev%3 == 2) & (numbers[i]%3 == 2)) {
                r_dist = abs(numbers[i] - r_prev)/3;
            } else {
                r_dist = abs(numbers[i] - r_prev);
            }
            if(l_dist < r_dist) {
                answer = answer + "L";
                l_prev = numbers[i];
            } else if(l_dist > r_dist) {
                answer = answer + "R";
                r_prev = numbers[i];
            } else {
                if(hand == "right") {
                    answer = answer + "R";
                    r_prev = numbers[i];
                } else {
                    answer = answer + "L";
                    l_prev = numbers[i];
                }
            }
        }
    }
    
    return answer;
}
