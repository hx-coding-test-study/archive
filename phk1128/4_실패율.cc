#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
        vector<pair<int, double>> result;
        queue<int> q;

        sort(stages.begin(), stages.end());
        for (int stage : stages) {
            q.push(stage);
        }

        int stage = 1;
        double count = 0;
        double remaining = stages.size();

        while (stage <= N) {
            if (!q.empty() && q.front() <= stage) {
                q.pop();
                count++;
            } else {
                double rate = (remaining == 0) ? 0 : count / remaining;

                result.push_back({stage, rate});
                remaining -= count;
                stage++;
                count = 0;
            }
        }

        sort(result.begin(), result.end(),
             [](const auto& a, const auto& b) {
                 if (a.second != b.second) {
                     return a.second > b.second;
                 }
                 return a.first < b.first;
             });

        vector<int> answer;
        for (const auto& item : result) {
            answer.push_back(item.first);
        }

        return answer;
    }