#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

// today "2022.05.19"
// terms ["A 6", "B 12", "C 3"]
// privacies ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]
// result [1, 3]
// 모든 달은 28일까지 있다고 가정

vector<int> solution(string today, vector<string> terms,
                     vector<string> privacies) {
  vector<int> answer;

  int curr_year, curr_month, curr_day;
  int arr[26];

  sscanf(today.c_str(), "%d.%d.%d", &curr_year, &curr_month, &curr_day);

  for (int i = 0; i < (int)terms.size(); i++) {
    char c;     // 약관 종류
    int length; // 유효기간
    sscanf(terms[i].c_str(), "%c %d", &c, &length);

    arr[c - 'A'] = length;
  }

  for (int i = 0; i < (int)privacies.size(); i++) {
    int year, month, day;
    char c;
    sscanf(privacies[i].c_str(), "%d.%d.%d %c", &year, &month, &day, &c);
    int length = arr[c - 'A'];

    int curr_dates = curr_year * 12 * 28 + curr_month * 28 + curr_day;
    int expire_dates = year * 12 * 28 + month * 28 + day + length * 28;

    if (curr_dates >= expire_dates) {
      answer.push_back(i + 1);
    }
  }

  return answer;
}