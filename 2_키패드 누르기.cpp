#include <string>
#include <vector>
#include <tuple>
#include <bits/stdc++.h>

using namespace std;

int curr_left = 10;
int curr_right = 12;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int arr[4][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12}
};

bool inRange(int r, int c) {
    return (r >= 0 && r < 4 && c >= 0 && c < 3);
}

int BFS(int r, int c, int ansR, int ansC) {

    if(r == ansR && c == ansC) return 0;
        
    queue<pair<int, int>> Q;
    bool visited[4][3] = {false, };
    int dist[4][3] = {0, };

    Q.push({r, c});
    visited[r][c] = true;

    int cnt = 0;

    while(!Q.empty()) {
        int sr, sc;
        tie(sr, sc) = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = sr + dr[i];
            int nc = sc + dc[i];

            if(inRange(nr, nc) && !visited[nr][nc]) {
                dist[nr][nc] = dist[sr][sc] + 1;
                if(nr == ansR && nc == ansC) {
                    return dist[nr][nc];
                }
                Q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
    return -1;
}

string temp;

// 더 가까운 위치를 찾기
void move(int num, string hand) { // 2 left
    if(num == 0) num += 11;
    int ans_r = (num-1) / 3;
    int ans_c = (num-1) % 3;
    int l_r = (curr_left-1) / 3;
    int l_c = (curr_left-1) % 3;
    int r_r = (curr_right-1) / 3;
    int r_c = (curr_right-1) % 3;

    int dist_l = BFS(l_r, l_c, ans_r, ans_c);
    int dist_r = BFS(r_r, r_c, ans_r, ans_c);

    if (dist_l == dist_r) {
        if (hand == "left") {
            curr_left = num;
            temp = "L";
        }
        else {
            curr_right = num;
            temp = "R";
        }
    }
    else if (dist_l > dist_r) {
        curr_right = num;
        temp = "R";
    }
    else {
        curr_left = num;
        temp = "L";
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    for(int i = 0; i < (int)numbers.size(); i++) {

        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            curr_left = numbers[i];
            answer += "L";
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            curr_right = numbers[i];
            answer += "R";
        }
        else {
            move(numbers[i], hand);
            answer += temp;
        }
    }
    return answer;
}