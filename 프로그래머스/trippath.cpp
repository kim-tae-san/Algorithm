#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

vector<vector<string> > v;
bool visited[10001] = {0,};
vector<vector<string> > ans;

void dfs(int cnt, int n, vector<vector<string> >& tickets){
    if(cnt == n-1){
        vector<string> temp;
        for(auto i:v){
            temp.push_back(i[0]);
        }
        temp.push_back(v[v.size()-1][1]);
        ans.push_back(temp);
        return;
    }
    for(int i=0; i<n; i++){
        if(visited[i] || v[v.size()-1][1] != tickets[i][0]) continue;
        //cout << v[v.size()-1][1] << " " << tickets[i][0] << endl;
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
    /*for(auto i: tickets){
        cout << i[0] << " " << i[1] << endl << endl;
    }*/
    int n;
    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0] == "ICN"){
            n = i;
            break;
        }
    }
    v.push_back(tickets[n]);
    visited[n] = true;
    dfs(0, tickets.size(), tickets);
    
    return ans[0];
}

int main(){
    vector<vector<string> > tickets = {{"ICN", "SFO"}, {"ICN", "SFO"}, };
    solution(tickets);
}