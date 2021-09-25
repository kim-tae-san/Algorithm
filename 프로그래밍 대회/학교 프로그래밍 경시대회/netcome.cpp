/****************************************
    
    제 7회 한기대 프로그래밍 대회 F번 문제

    Input : total wage, score of company

    Output : netcome

    Calculates netcome


    
    9/25 coded by bmkim
    
******************************************/
#include <iostream>

using namespace std;

int solution(int p, int k){
    int n = (int) (3.0*p/(1+(9.0/k)));
    while(n/3 + n/k*3 < p){
        n++;
    }
    if(n/3 + n/k*3 == p)
        return n;
    return -1;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        int p, k;
        cin >> p >> k;
        cout << solution(p, k) << endl;
    }
}