#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int,double> a, pair<int,double> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
    
}

vector<int> solution(int N, vector<int> stages) {
    vector<double> state(502);
    vector<pair<int,double>> failratio;
    vector<int> answer;
    double user = 0; 

    // 스테이지별 클리어하지 못한 플레이어 수
    // state = [1 3 2 1 0 1]
    for(int j=0; j<stages.size(); j++) {
        state[stages[j]] = state[stages[j]] + 1;
    }
    for(int i=N+1; i>0; i--) {
        double fail = 0;
        user = user + state[i]; // i 스테이지에 도달한 플레이어 수
        if(state[i] == 0) {
            fail = 0;
        } else {
            fail = state[i] / user;
        }
        // std::cout << i << " " << state[i] << " " << user << " " << fail << std::endl;
        if(i != N + 1) {
            failratio.push_back(make_pair(i, fail));
        }
    }
    
    sort(failratio.begin(), failratio.end(), compare);
    // for(int i=0; i<N; i++) {
    //     std::cout << failratio[i].first << " " << failratio[i].second << std::endl;
    // }
    
    for(int i=0; i<N; i++) {
        answer.push_back(failratio[i].first);
    }
    
    return answer;
}
