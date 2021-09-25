/****************************************
    
    제 6회 한기대 프로그래밍 대회 J번 문제

    Input : string word

    Output : moved num

    Calculates moved num


    
    9/25 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int solution(string word){
    char collection[5] = {'A','E','I','O','U'};
    int ret = 0;
    for(int i=0;i<word.size();i++){
        for(auto j:collection){
            if(word[i] == j){
                ret += word.size() - i - 1;
                break;
            }
        }
    }
    return ret;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        string word;
        cin >> word;
        cout << solution(word) << endl;
    }
}