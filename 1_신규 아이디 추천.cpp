#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 유사하면서 규칙에 맞는 아이디 추천
// 3이상 15이하
// 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.) 문자만 사용
// 마침표(.)는 처음과 끝에 사용할 수 없으며 또한 연속으로 사용할 수 없음

string solution(string new_id) {
  string answer = "";

  // 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
  for (char &c : new_id) {
    if (isupper(c)) {
      c = tolower(c);
    }
  }

  // 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한
  // 모든 문자를 제거합니다.
  string new_id2;
  for (char &c : new_id) {
    if (c == '.' || c == '_' || c == '-' || islower(c) || isdigit(c)) {
      new_id2 += c;
    }
  }

  // 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로
  // 치환합니다.
  while (new_id2.find("..") != string::npos) {
    int pos = new_id2.find("..");
    new_id2.replace(pos, 2, ".");
  }

  // 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
  if (!new_id2.empty() && new_id2.front() == '.') {
    new_id2.erase(0, 1);
  }
  if (!new_id2.empty() && new_id2.back() == '.') {
    new_id2.pop_back();
  }

  // 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
  if (new_id2.empty()) {
    new_id2 = "a";
  }

  // 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한
  // 나머지 문자들을 모두 제거합니다.만약 제거 후 마침표(.)가 new_id의 끝에
  // 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
  if ((int)new_id2.size() >= 16) {
    new_id2.erase(15, (int)new_id2.size() - 15);

    while (new_id2.back() == '.') {
      new_id2.pop_back();
    }
  }

  // 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가
  // 3이 될 때까지 반복해서 끝에 붙입니다.

  if ((int)new_id2.size() <= 2) {
    char last_char = new_id2.back();
    while ((int)new_id2.size() != 3) {
      new_id2 += last_char;
      // new_id2.push_back(last_char);
    }
  }

  answer = new_id2;

  return answer;
}