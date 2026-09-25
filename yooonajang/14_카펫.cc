#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int y=1; y<=yellow; y++) {
        int rest = yellow % y;
        int x = yellow / y;
        if (rest==0 && x >= y){
            int browny = 4 + 2*(x+y);
            if (brown == browny){
                answer.push_back(x+2);
                answer.push_back(y+2);
            }
        }
    }
    return answer;
}
