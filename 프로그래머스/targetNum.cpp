#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[20] = {0,};

int dfs(int cnt, int end, vector<int>& numbers, int target, int start){
    if(cnt == end){
        int ret= 0;
        for(auto i:numbers){
            ret += i;
            cout << i;
        }
        cout << endl;
        if(target == ret)
            return 1;
        return 0;
    }
    int result = 0;
    for(int i=start; i<numbers.size(); i++){
        if(visited[i]) continue;
        visited[i] = true;
        numbers[i] *= -1;
        result += dfs(cnt + 1, end, numbers, target, i);
        visited[i] = false;
        numbers[i] *= -1;
    }
    return result;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    for(int i=1; i<= numbers.size(); i++){
        answer += dfs(0, i, numbers, target, 0);
    }
    return answer;
}

int main(){
    vector<int> numbers = {1, 2, 3, 4, 5};
    int target = 3;
    cout << solution(numbers, target);
}