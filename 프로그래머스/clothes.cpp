/****************************************
    
    Programmers LV2. clothes

    Input : clothes vector

    Output : Number of clothes Combinations

    Calculates number of clothes combination using DFS

    
    9/12 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool visited[50] = {0,};
unordered_map<string, int> hash_map;

int dfs(vector<vector<string> >clothes, int cnt, int start, int end){
    int ret = 0;
    if(cnt == end){
        return 1;
    }
    for(int i=start; i<clothes.size(); i++){
        if(visited[i] == true || hash_map[clothes[i][1]] > 0)
            continue;
        visited[i] = true;
        hash_map[clothes[i][1]] += 1;
        ret += dfs(clothes, cnt + 1, i, end);
        visited[i] = false;
        hash_map[clothes[i][1]] -= 1;
    }
    return ret;
}
int solution(vector<vector<string> > clothes) {
    int answer = 0;
    for(int i=0; i<clothes.size(); i++){
        hash_map[clothes[i][1]] = 0;
    }
    for(int i=1; i<=hash_map.size(); i++){
        answer += dfs(clothes, 0, 0, i);
    }
    return answer;
}

int main(){
    vector<vector<string> > clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    vector<vector<string> > clothes2 = {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}};
    cout << solution(clothes2);
}