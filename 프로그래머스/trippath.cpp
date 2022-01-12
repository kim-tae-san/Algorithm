#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

vector<vector<string> > v;
bool visited[10001] = {0,};
vector<string> ans;

void dfs(int cnt, int n, vector<vector<string> >& tickets){
    // 모든 티켓을 사용한 경우 종료 조건
    if(cnt == n-1){
        vector<string> ans;
        for(auto i:v){
            ans.push_back(i[0]);
        }
        ans.push_back(v[v.size()-1][1]);
        return;
    }
    for(int i=0; i<n; i++){
        // 방문했거나 이전 티켓의 목적지와 현재 티켓의 출발지가 일치하지 않을 경우 다음 티켓으로
        if(visited[i] || v[v.size()-1][1] != tickets[i][0]) continue;
        cout << v[v.size()-1][0] << " " << v[v.size()-1][1] << " " << cnt << " "  << i << endl;
        visited[i] = true;
        v.push_back(tickets[i]);
        dfs(cnt + 1, n, tickets);
        v.pop_back();
        visited[i] = false;
    }
}

vector<string> solution(vector<vector<string> > tickets) {
    // 알파벳 순으로 정렬후 깊이 우선 탐색으로 처음 발견하는 경로가 정답
    sort(tickets.begin(), tickets.end());
    vector<int> start;
    int n;
    for(auto i: tickets){
        cout << i[0] << " " << i[1] << endl << endl;
    }
    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0] == "ICN"){
            n = i;
            break;
        }
    }
    v.push_back(tickets[n]);
    visited[n] = true;
    dfs(0, tickets.size(), tickets);

    for(auto i:ans)
        cout << i << endl;
    return ans;
}

int main(){
    vector<vector<string> > tickets = {{"ICN", "BOO"}, {"ICN", "COO"}, {"COO", "DOO"}, {"DOO", "COO"}, {"BOO", "DOO"}, {"DOO", "BOO"}, {"BOO", "ICN"}, {"COO", "BOO"}};

    solution(tickets);
}