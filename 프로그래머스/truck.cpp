/****************************************
    
    Programmers Lv2. 다리를 지나는 트럭

    Input : Bridge Max weight, Bridge length, Truck vector

    Output : Total Time of Crossing bridge

    Calculates Total time using queue


    
    9/20 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int truck_index = 0;
    int current_weight = 0;
    queue<int> bridge;
    for(int i=0; i<bridge_length; i++)
        bridge.push(0);
    while(truck_index < truck_weights.size()){
        int w = bridge.front(); bridge.pop();
        int next_truck = truck_weights[truck_index];
        current_weight -= w;
        if(current_weight + next_truck <= weight){
            bridge.push(next_truck);
            current_weight += next_truck;
            truck_index++;
        }
        else{
            bridge.push(0);
        }
        answer++;
    }
    return answer + bridge_length;
}