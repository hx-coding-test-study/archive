#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

// 실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을
// return 하도록 solution 함수를 완성하라.

// 만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 하면
// 된다.

bool compare(pair<double, int> &a, pair<double, int> &b) {

  if (a.first != b.first) {
    return a.first > b.first;
  }

  return a.second < b.second;
}

vector<int> solution(int N, vector<int> stages) {
  vector<int> answer;

  vector<int> counts(N + 2, 0);
  for (int i = 0; i < (int)stages.size(); i++) {
    counts[stages[i]]++;
  }

  // 스테이지 번호 0 1 2 3 4 5 6
  // counts     0 1 3 2 1 0 1
  //            0 5 0 0 0 0

  vector<pair<double, int>> fail_ratios; // 실패율과 스테이지 번호 저장

  int size = (int)stages.size();

  for (int i = 1; i <= N; i++) {
    double failRatio;

    if (size == 0) {
      failRatio = 0.0;
    } else {
      failRatio = (double)counts[i] / size;
    }
    fail_ratios.push_back({failRatio, i});

    size = size - counts[i];
  }

  sort(fail_ratios.begin(), fail_ratios.end(), compare);

  for (int i = 0; i < (int)fail_ratios.size(); i++) {
    answer.push_back(fail_ratios[i].second);
  }

  return answer;
}