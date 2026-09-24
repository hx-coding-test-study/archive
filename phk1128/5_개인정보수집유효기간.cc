#include <string>
#include <vector>
#include <map>
using namespace std;

int toDays(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    return year * 12 * 28 + (month - 1) * 28 + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    map<char, int> period;
    vector<int> answer;
    int current = toDays(today);

    for (string term : terms) {
        period[term[0]] = stoi(term.substr(2));
    }

    for (int i = 0; i < privacies.size(); i++) {
        int collected = toDays(privacies[i].substr(0, 10));
        char type = privacies[i][11];

        if (collected + period[type] * 28 <= current) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}