/****************************************
    
    제 7회 한기대 프로그래밍 대회 E번 문제

    Input : adjacent node vector, start point

    Output : maximum depth of graph(Tree)

    Calculates maximum depth of tree using stack


    
    9/23 coded by bmkim
    
******************************************/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<pair<int, int> > > adjacent, int start, bool find){
    stack<pair<int, int> > s;
    int vertex, ret = 0;
    vector<bool> visited(10001, 0);
    s.push(make_pair(start, 0));
    visited[start] = true;
    while(!s.empty()){
        int elem = s.top().first;
        int level = s.top().second;
        s.pop();
        visited[elem] = true;
        for(auto i:adjacent[elem]){
            if(!visited[i.first]){
                s.push(make_pair(i.first, level + 1));
            }
        }
        if(level > ret){
            ret = level;
            vertex = elem;
        }
    }
    if(find)
        ret = vertex;
    return ret;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        int n;
        int ret = 0;
        cin >> n;
        vector<vector<pair<int, int> > > adjacent(10001);
        n--;
        while(n--){
            int from, to;
            cin >> from >> to;
            adjacent[from].push_back(make_pair(to, 0));
            adjacent[to].push_back(make_pair(from, 0));
        }
        cout << solution(adjacent, solution(adjacent, 1, true), false) << endl;
    }
}