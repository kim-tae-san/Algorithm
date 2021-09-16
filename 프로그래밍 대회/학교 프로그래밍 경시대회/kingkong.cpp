#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool isok(int i, int n){
    return i >= 0 && i < n;
}
string solution(string state){
    vector<int> checked;
    int n = state.size();
    while(true){
        checked = vector<int>();
        bool flag = true;
        for(int i=0; i<n; i++){
            if(isok(i - 1, n) && state[i] == 'L'){
                if(state[i - 1] == '.'){
                    state[i - 1] = 'L';
                    flag = false;
                }
                else if(state[i-1] == 'R'){
                    if(find(checked.begin(), checked.end(), i - 1) != checked.end()){
                        state[i-1] = '.';
                    }
                }
            }
            else if(isok(i+1, n) && state[i] == 'R'){
                if(state[i+1] == '.'){
                    if(isok(i-1, n) && state[i + 2] == 'L'){
                        i += 3;
                    }
                    else{
                        state[i + 1] = 'R';
                        checked.push_back(i + 1);
                        flag = false;
                        i++;
                    }
                }
            }
        }
        if(flag)
            return state;
    }
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