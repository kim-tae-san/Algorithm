/****************************************
    
    Programmers LV3 디스크 컨트롤러

    Input : vector<vector<int>> processes

    Output : int consumed mean time

    Calculates processes's mean time using heap


    
    9/25 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    if(a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int> > jobs) {
    int answer = 0;
    int index = 0;
    int timer = 0;
    priority_queue<pair<int, int> > pq;
    sort(jobs.begin(), jobs.end(), compare);
    pq.push(make_pair(-jobs[index][1], jobs[index][0]));
    timer = jobs[index][0];
    index++;
    while(index < jobs.size() || !pq.empty()){
        if(pq.empty()){
            pq.push(make_pair(-jobs[index][1], jobs[index][0]));
            timer = jobs[index][0];
            index++;
        }
        pair<int, int> process = pq.top(); pq.pop();
        timer += -process.first;
        answer += timer - process.second;
        for(int i = index; i<jobs.size(); i++){
            if(jobs[i][0] > timer){
                break;
            }
            pq.push(make_pair(-jobs[i][1], jobs[i][0]));
            index++;
        }
    }
    return answer/jobs.size();
}

int main(){
    vector<vector<int> > a = {{0, 3}, {4, 9}, {15, 2}};
    cout << solution(a);
}