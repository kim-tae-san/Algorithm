/****************************************
    
    제 7회 한국기술교육대 프로그래밍 대회 I번 문제

    Input : Current state string

    Output : result state string

    Simulate the game

    
    9/17 coded by bmkim
    
******************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Pattern => L..R R.L R..L
string solution(string states){
    pair<int, char> state = make_pair(-1, '.');
    int cnt = 0;
    for(int i=0; i<states.size(); i++){
        if(states[i] == 'R' || states[i] == 'L'){
            state = make_pair(i, states[i]);
            if(states[i] == 'L'){
                for(int j=0; j<i; j++)
                    states[j] = 'L';
            }
            break;
        }
    }
    for(int i = state.first + 1; i<states.size(); i++){
        if(states[i] == '.')
            cnt++;
        else if(states[i] == 'R'){
            if(state.second == 'R'){
                for(int k = state.first; k < i; k++)
                    states[k] = 'R';
            }
            cnt = 0;
            state = make_pair(i, 'R');
        }
        else{
            if(state.second == 'R'){
                if(cnt % 2 == 0){
                    for(int k = 1; k < (i - state.first)/2 + 1; k++){
                        states[state.first + k] = 'R';
                        states[i-k] = 'L';
                    }
                }
                else{
                    for(int k = 1; k < (i - state.first)/2; k++){
                        states[state.first + k] = 'R';
                        states[i-k] = 'L';
                    }
                }
            }
            else{
                for(int k = state.first; k < i; k++)
                    states[k] = 'L';
            }
            cnt = 0;
            state = make_pair(i, 'L');
        }
    }
    if(state.second == 'R'){
        for(int i = state.first; i < states.size(); i++)
            states[i] = 'R';
    }
    return states;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        string state;
        cin >> state;
        cout << solution(state) << endl;
    }
}