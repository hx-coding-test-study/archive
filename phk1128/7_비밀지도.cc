#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        int value = arr1[i] | arr2[i];
        string row;

        for (int j = n - 1; j >= 0; j--) {
            row += (value & (1 << j)) ? '#' : ' ';
        }

        answer.push_back(row);
    }

    return answer;
}