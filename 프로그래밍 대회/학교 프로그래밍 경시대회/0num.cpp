/****************************************
    
    제 8회 한기대 프로그래밍 대회 E번 문제

    Input : int n

    Output : 0's num

    Calculates lasting 0's num using Mathematical logic


    
    10/4 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>
using namespace std;

int solution(int n){
    int ret = 0;
    while(n/5 > 0){
        n /= 5;
        ret++;
    }
    return ret;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        int n;
        cin >> n;
        cout << solution(n) << endl;
    }
}