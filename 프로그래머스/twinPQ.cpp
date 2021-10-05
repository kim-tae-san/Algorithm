/****************************************
    
    Programmers Lv3. 이중우선순위 큐

    Input : vector<string> operations

    Output : [max elem, min elem]

    Develop the Twin Priority Queue

    
    10/5 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> minq;
    priority_queue<int> maxq;
    int cap = 0;
    
    for(auto i:operations){
        if(cap == 0){
            minq = priority_queue<int>();
            maxq = priority_queue<int>();
        }
        vector<string> oper;
        stringstream ss(i);
        string stringbuffer;
        while(getline(ss, stringbuffer, ' ')){
            oper.push_back(stringbuffer);
        }
        int n = stoi(oper[1]);
        if(oper[0] == "I"){
            minq.push(-n);
            maxq.push(n);
            cap++;
        }
        else{
            if(n == 1 && cap){
                maxq.pop();
            }
            else if(n == -1 && cap){
                minq.pop();
            }
            cap = max(0, cap - 1);
        }
    }
    if(cap)
    {
        answer.push_back(maxq.top());
        answer.push_back(-minq.top());
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}