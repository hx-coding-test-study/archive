#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    map<string, int> dictionary;
    vector<int> answer;
    int nextIndex = 27;

    for (int i = 0; i < 26; i++) {
        dictionary[string(1, 'A' + i)] = i + 1;
    }

    int i = 0;

    while (i < msg.size()) {
        string word(1, msg[i]);
        int j = i + 1;

        while (j < msg.size() && dictionary.count(word + msg[j])) {
            word += msg[j];
            j++;
        }

        answer.push_back(dictionary[word]);

        if (j < msg.size()) {
            dictionary[word + msg[j]] = nextIndex++;
        }

        i = j;
    }

    return answer;
}