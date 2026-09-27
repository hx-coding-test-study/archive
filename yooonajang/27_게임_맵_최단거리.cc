// 프로그래머스 1844 - 게임 맵 최단거리 (BFS)
// https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));   // -1 = 미방문, 방문체크+거리기록 겸용
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    queue<pair<int,int>> q;

    q.push({0, 0});
    dist[0][0] = 1;   // 시작 칸도 세어야 하므로 1부터 시작

    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m
                && dist[new_x][new_y] == -1 && maps[new_x][new_y] == 1) {
                dist[new_x][new_y] = dist[x][y] + 1;
                q.push({new_x, new_y});
            }
        }
    }

    return dist[n-1][m-1];   // 도달 못 했으면 -1이 그대로 남아있음
}
