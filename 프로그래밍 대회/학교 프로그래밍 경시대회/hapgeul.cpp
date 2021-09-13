/****************************************
    
    결! 합! 제 7회 한국기술교육대학교 프로그래밍 경시대회 2번문제

    Input : Card Information, Player's turn data

    Output : Player's total score

    Implement 결! 합! Game


    
    9/13 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

set<set<int> > answer;
vector<int> v;
bool checked[16] = {0,};

void init(vector<vector<string> > &board, int cnt, int start){
    if(cnt == 3){
        bool flag = true;
        for(int i=0; i<3; i++){
            if(board[v[0]][i] == board[v[1]][i]){
                if(board[v[2]][i] != board[v[0]][i])
                    flag = false;
            }
            else{
                if(board[v[0]][i] == board[v[2]][i] || board[v[1]][i] == board[v[2]][i])
                    flag = false;
            }
        }
        if(flag){
            set<int> partialAns;
            for(auto i:v)
                partialAns.insert(i + 1);
            answer.insert(partialAns);
        }
        return;
    }
    for(int i=start; i<board.size();i++){
        if(checked[i])
            continue;
        v.push_back(i);
        checked[i] = true;
        init(board, cnt + 1, i);
        v.pop_back();
        checked[i] = false;
    }
    return;
}

bool isanswer(set<int> query){
    if(answer.find(query) == answer.end()){
        return false;
    }
    return true;
}

bool hap(){
    set<int> shouted;
    for(int i=0;i<3;i++){
        int n;
        cin >> n;
        shouted.insert(n);
    }
    if(isanswer(shouted)){
        answer.erase(answer.find(shouted));
        return true;
    }
    return false;
}
bool geol(){
    if(answer.empty())
        return true;
    return false;
}
vector<int> Solution(vector<vector<string> > & board){
    vector<int> ret = {0, 0};
    int player = 0;
    init(board, 0, 0);
    while(true){
        char shout;
        cin >> shout;
        if(shout == 'H'){
            if(hap()){
                ret[player%2]++;
            }
            else{
                if(ret[player%2] != 0){
                    ret[player%2]--;
                }
            }
        }
        else if(shout == 'G'){
            if(geol()){
                ret[player%2] += 3;
                break;
            }
            else{
                if(ret[player%2] != 0){
                    ret[player%2]--;
                }
            }
        }
        player++;
    }
    return ret;
}
int main(){
    int c;
    cin >> c;
    while(c--){
        vector<vector<string> > board;
        for(int i=0; i<9; i++){
            vector<string> state;
            for(int j=0; j<3; j++){
                string temp;
                cin >> temp;
                state.push_back(temp);
            }
            board.push_back(state);
        }
        vector<int> ret = Solution(board);
        for(auto i:ret)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}