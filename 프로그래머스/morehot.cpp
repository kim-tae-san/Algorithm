/****************************************
    
    Programmers Lv.2 더 맵게

    Input : vector<int>, cutline int

    Output : int

    Calculate the number of assembles using Priority Queue
    
    9/22 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long> hot;
    for(auto i:scoville)
        hot.push(-i);
    while(-hot.top() < K){
        if(hot.size() < 2){
            if(-hot.top() >= K)
                answer++;
            else{
                return -1;
            }
            break;
        }
        long long morehot = 0;
        morehot += -hot.top();
        hot.pop();
        morehot += -hot.top()*2;
        hot.pop();
        hot.push(-morehot);
        answer++;
    }
    return answer;
}