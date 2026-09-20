#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<vector<int>> result_arr(n, vector<int>(n));
    vector<string> answer(n);
    for(int i=0; i<n; i++) {
        int x1 = arr1[i];
        int x2 = arr2[i];
        for(int j=0; j<n; j++) {
            // std::cout << i << " " << j << " " << x1 << " " << x2 << std::endl;
            if((x1%2)==1 || (x2%2)==1) {
                result_arr[i][n-j-1] = 1;
            }
            x1 = x1/2;
            x2 = x2/2;
        }
    }
    for(int i=0; i<n; i++) {
        answer[i] = "";
        for(int j=0; j<n; j++) {
            if(result_arr[i][j] == 1) {
                answer[i] = answer[i] + "#";
            } else {
                answer[i] = answer[i] + " ";
            }
        }
    }
    return answer;
}
