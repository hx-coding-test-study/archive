#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int solution(string numbers) {
    int answer = 0;

    // 011 - 1 / 10 / 11 / 101 / 110

    set<int> s;

    // 1자리부터 numbers max 자리수까지 모두 만들어보자.
    for (int i=1; i <= numbers.size(); i++){

        sort(numbers.begin(), numbers.end()); //매번 정렬

        do {
            string sub = numbers.substr(0, i); //얘가 길이만큼 sub 자르기
            int num = stoi(sub);
            // cout << numbers << ","<< num << endl;
            for (int j =2 ; j<= num; j++){
                if (num % j == 0 && num != j ) {
                    break;
                }
                else if (num % j == 0 && num == j) {
                    s.insert(num);
                    cout << num << endl;
                }

            }

        } while(next_permutation(numbers.begin(), numbers.end()));


    }
    answer = s.size();

    return answer;
}
