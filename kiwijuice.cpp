#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class KiwiJuiceEasy{
public:
    vector <int> thePouring(vector <int> capacities, vector <int> bottles,
        vector <int> fromId, vector <int> toId){
            // to에는 sum과 용량중 작은값, from에는 총합에서 to의 결과를 빼준값
            for(int i=0; i<fromId.size();i++){
                int sum = bottles[fromId[i]] + bottles[toId[i]];
                bottles[toId[i]] = min(capacities[toId[i]], sum);
                bottles[fromId[i]] = sum - bottles[toId[i]];
            }
            return bottles;
        }
};

int main(){
    vector <int> capacities = {700000, 800000, 900000, 1000000};
    vector <int> bottles = {478478, 478478, 478478, 478478};
    vector <int> fromId = {2, 3, 2, 0, 1};
    vector <int> toId = {0, 1, 1, 3, 2};
    KiwiJuiceEasy kiwijuice;
    vector <int> result = kiwijuice.thePouring(capacities, bottles, fromId, toId);
    for(auto i:result){
        printf("%d \n", i);
    }
}