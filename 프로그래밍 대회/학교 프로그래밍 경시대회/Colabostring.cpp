/****************************************
    
    제 8회 한기대 프로그래밍 대회 A번 문제

    Input : string

    Output : possible



    
    10/02 coded by bmkim
    
******************************************/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int c;

string solution(string s){
    sort(s.begin(), s.end());
    char check = s[0];
    int count = 1;
    for(int i=0; i<s.size(); i++){
        if(i%c == 0){
            count = 1;
            check = s[i];
        }
        else{
            if(s[i] != check)
                return "false";
            count++;
        }
    }
    if(count == c)
        return "true";
    return "false";
}
int main(){
    string target = "";
    cin >> c;
    for(int i=0; i<c; i++){
        string temp;
        cin >> temp;
        target += temp;
    }
    cout << solution(target);
}