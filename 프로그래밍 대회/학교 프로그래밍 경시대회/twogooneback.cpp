/****************************************
    
    제 8회 한기대 프로그래밍 경시대회 B번 문제

    Input : Matrix of Load

    Output : Fastest Path

    Calculates Fastest Path using BFS


    
    10/3 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int state[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

bool isok(int a, int b, int n){
    return a >= 0 && a < n && b>=0 && b< n;
}

int solution(vector<vector<int> >& matrix, vector<vector<bool> >& visited){
    if(matrix[0][0] == 0)   return -1;
    queue<pair<pair<int, int>, int> > s;
    s.push(make_pair(make_pair(0, 0), 0));
    visited[0][0] = true;
    while(!s.empty()){
        pair<pair<int, int>, int> current = s.front();
        s.pop();
        int x = current.first.second;
        int y = current.first.first;
        if(x == matrix.size()-1 && y == matrix.size()-1){
            return current.second;
        }
        for(int i=0; i<4; i++){
            int nextX = x + state[i][1];
            int nextY = y + state[i][0];
            if(isok(nextX, nextY, matrix.size()) && !visited[nextY][nextX] && matrix[nextY][nextX] == 1){
                s.push(make_pair(make_pair(nextY, nextX), current.second + 1));
                visited[nextY][nextX] = true;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > matrix;
    vector<vector<bool> > visited;
    for(int i=0; i<n;i++){
        vector<int> temp;
        vector<bool> tmp;
        for(int j=0; j<n;j++){
            int load;
            cin >> load;
            temp.push_back(load);
            tmp.push_back(false);
        }
        matrix.push_back(temp);
        visited.push_back(tmp);
    }
    int result = solution(matrix, visited);
    if(result == -1)
        cout << -1;
    else{
        result > 2 ? result = 3*(result-2) + 2 : result = result;
        cout << result;
    }
}