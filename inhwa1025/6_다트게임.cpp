#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int ptr = 0;
    vector<int> result(3);
    int res_ptr = 0;
    while((ptr < dartResult.size()) & (res_ptr < 3)) {
        string score = "";
        int now_result = 0;
        char bonus = '\0';
        while((ptr < dartResult.size()) & isdigit(dartResult[ptr])) {
            score.push_back(dartResult[ptr]);
            ptr = ptr + 1;
        }
        now_result = stoi(score);
        bonus = dartResult[ptr];
        if(bonus == 'D') {
            now_result = now_result * now_result;
        } else if(bonus == 'T') {
            now_result = now_result * now_result * now_result;
        }
        ptr = ptr + 1;
        if(dartResult[ptr] == '*') {
            now_result = now_result * 2;
            if(res_ptr>0) {
                result[res_ptr-1] = result[res_ptr-1] * 2;
                std::cout << res_ptr-1 << " " << result[res_ptr-1] << std::endl;
            }
            ptr = ptr + 1;
        } else if(dartResult[ptr] == '#') {
            now_result = now_result * (-1);
            ptr = ptr + 1;
        }
        //std::cout << res_ptr << " " << now_result << std::endl;
        result[res_ptr] = now_result;
        res_ptr = res_ptr + 1;
    }
    for(int j=0; j<3; j++) {
        answer = answer + result[j];
    }
    return answer;
}
