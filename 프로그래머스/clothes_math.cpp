/****************************************
    
    Programmers LV2. clothes

    Input : clothes vector

    Output : Number of clothes Combinations

    Calculates number of clothes combination using math algorithm

    
    9/12 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 1;
    unordered_map<string, int> hash_map;
    for(int i=0; i<clothes.size();i++){
        hash_map[clothes[i][1]] = 0;
    }
    for(int i=0; i<clothes.size();i++){
        hash_map[clothes[i][1]] += 1;
    }
    unordered_map<string, int>::iterator itr;
    for(itr = hash_map.begin(); itr != hash_map.end(); itr++){
        answer *= itr->second + 1;
    }
    answer--;
    return answer;
}

int main(){
    vector<vector<string> > clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    vector<vector<string> > clothes2 = {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}};
    vector<vector<string> > clothes3 = {{"asd", "face"}, {"sdf", "head"}, {"asdfds", "eyes"}, {"sdffd", "pants"}};
    cout << solution(clothes);
}