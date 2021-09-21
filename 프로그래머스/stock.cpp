/****************************************
    
    Programmers Lv2. 주식가격

    Input : vector<int>

    Output : vector<int>

    Calculates stock's maintain term


    
    9/21 coded by bmkim
    
******************************************/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0; i<prices.size(); i++){
        int ret = 0;
        for(int j=i + 1; j<prices.size(); j++){
            ret++;
            if(prices[i] > prices[j])
                break;
        }
        answer.push_back(ret);
    }
    return answer;
}