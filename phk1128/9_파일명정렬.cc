#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <utility>
using namespace std;

pair<string, int> splitFileName(const string& file) {
    int start = 0;

    while (!isdigit(file[start])) {
        start++;
    }

    int end = start;

    while (end < file.size() && isdigit(file[end])) {
        end++;
    }

    string head = file.substr(0, start);

    for (char& c : head) {
        c = tolower(c);
    }

    return {head, stoi(file.substr(start, end - start))};
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), [](const string& a, const string& b) {
        pair<string, int> first = splitFileName(a);
        pair<string, int> second = splitFileName(b);

        if (first.first != second.first) {
            return first.first < second.first;
        }

        return first.second < second.second;
    });

    return files;
}