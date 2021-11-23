#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int> > computers) {
    int answer = 0;
    stack<int> s;
    bool visited[200] = {0,};
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        s.push(i);
        while(!s.empty()){
            int current = s.top();
            visited[current] = true;
            s.pop();
            for(int j=0; j<computers[i].size(); j++){
                if(!visited[j] && computers[current][j] == 1){  // 현재 노드와 연결된 노드상태가 활성화되어있고 방문안했으면 스택에 추가
                    s.push(j);
                }
            }
        }
        answer++;
    }
    return answer;
}