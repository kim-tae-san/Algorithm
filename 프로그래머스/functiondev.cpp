/****************************************
    
    Programmers Lv2. 기능개발

    Input : two vectors<int>

    Output : deployed num vector<int>

    Calculates deploy num


    
    9/14 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = 0;
    while(n < progresses.size()){
        for(int i=0; i<progresses.size(); i++){
            progresses[i] += speeds[i];
        }
        int cnt = 0;
        while(progresses[n] >= 100 && n < progresses.size()){
            n++;
            cnt++;
        }
        if(cnt > 0){
            answer.push_back(cnt);
        }
    }
    return answer;
}