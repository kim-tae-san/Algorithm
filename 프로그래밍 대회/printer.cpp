/****************************************
    
    Programmers Lv2. Printer

    Input : vector of priorities, object location

    Output : num of object's coming out 

    Calculates coming out of object using queue


    
    9/15 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<int> q;
    for(int i=0; i<priorities.size(); i++){
        q.push(priorities[i]);
    }
    while(true){
        if(location < 0){
            location = q.size() - 1;
        }
        int prior = q.front();
        bool flag = true;
        q.pop();
        for(int i=0;i<q.size();i++){
            int temp = q.front();
            if(temp > prior)
                flag = false;
            q.pop();
            q.push(temp);
        }
        if(!flag){
            q.push(prior);
        }
        else if(location == 0){
            break;
        }
        else{
            answer++;
        }
        location--;
    }
    return answer;
}