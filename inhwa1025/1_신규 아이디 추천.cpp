#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    // step 1
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    // step 2
    string str2 = "";
    for(char c: new_id) {
        if((c>='a'&&c<='z') || (c>='0'&&c<='9') || c=='-' || c=='_' || c=='.') {
            str2 = str2 + c;
        }
    }
    // step 3
    string str3 = "";
    char prev = '\0';
    for(char c: str2) {
        if(prev!='.' || c!='.') {
            str3 = str3 + c;
        }
        prev = c;
    }
    // step 4
    if(str3[0] == '.') {
        str3 = str3.substr(1, -1);
    }
    if(str3[str3.length()-1] == '.') {
        str3 = str3.substr(0, str3.length()-1);
    }
    // step 5
    if(str3.length() == 0) {
        str3 = "a";
    }
    // step 6
    if(str3.length() >= 16) {
        str3 = str3.substr(0, 15);
    }
    if(str3[str3.length()-1] == '.') {
        str3 = str3.substr(0, str3.length()-1);
    }
    // step 7
    if(str3.length() <= 2) {
        for(int i=0; i < (3-str3.length()+1); i++){
            str3 = str3 + str3[str3.length()-1];
        }
    }
    answer = str3;
    return answer;
}
