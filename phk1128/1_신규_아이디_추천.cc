#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool isPass(char c); 

string solution(string new_id) {
    string answer = "";
    
    string lower = "";
    for (char c : new_id) {
        lower += tolower(c);
    }
    
    string tmpStr1 = "";
    for (int i = 0; i < lower.size(); i++) {
        char c = lower[i];
        if (isPass(c)) {
            tmpStr1 += c;
        }
    }
    string tmpStr2 = "";
    for (int i = 0; i < tmpStr1.size(); i++) {
        if(tmpStr1[i] == '.') {
            while (i < tmpStr1.size() - 1 && tmpStr1[i + 1] == '.') {
                i += 1;
            }
        }
        tmpStr2 += tmpStr1[i];
    }
    if (tmpStr2[0] == '.') {
        tmpStr2.erase(0,1);
    }
    
    int last = tmpStr2.size() - 1;
    if (tmpStr2[last] == '.') {
        tmpStr2.erase(last,1);
    }
    if (tmpStr2 == "") {
        tmpStr2 += "a";
    }
    int size = tmpStr2.size();
    if (size >= 16) {
        tmpStr2.erase(15);
        last = tmpStr2.size() - 1;
        if (tmpStr2[last] == '.') {
            tmpStr2.erase(last,1);
        }
    }
    size = tmpStr2.size();
    if (size <= 2) {
        char lastChar = tmpStr2[size - 1];
        while (tmpStr2.size() < 3) {
            tmpStr2 += lastChar;
        }
    }
    answer = tmpStr2;
    
    return answer;
}

bool isPass(char c) {
    return isalpha(c) ||
        isdigit(c) ||
        c == '-' ||
        c == '_' ||
        c == '.';
        
}