#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string cal_expire_date(string term_date, int term) {
    int expire_year = stoi(term_date.substr(0,4)) + (term/12);
    int expire_month = stoi(term_date.substr(5,7)) + (term%12);
    if(expire_month > 12) {
        expire_year = expire_year + 1;
        expire_month = expire_month - 12;
    }
    string expire_month_str = to_string(expire_month);
    if(expire_month < 10) {
        expire_month_str = "0" + expire_month_str;
    }
    return to_string(expire_year) + "." + expire_month_str + term_date.substr(7,10);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> privacy_mapping(100);
    for(int i=0; i<terms.size(); i++) {
        char term = terms[i][0];
        int term_int = (int)term;
        int term_day = stoi(terms[i].substr(2, terms[i].size()));
        privacy_mapping[term_int] = term_day;
    }
    for(int i=0; i<privacies.size(); i++) {
        string collect_day = privacies[i].substr(0,10);
        char collect_term = privacies[i][11];
        int collect_term_int = (int)collect_term;
        int term_day = privacy_mapping[collect_term_int];
        // std::cout << i+1 << " " << today << " " << cal_expire_date(collect_day, term_day) << endl;
        if(cal_expire_date(collect_day, term_day) <= today) {
            answer.push_back(i+1);
        }
    }
    //sort(answer.begin(), answer.end());
    return answer;
}
