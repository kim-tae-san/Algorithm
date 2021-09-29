/****************************************
    
    제 6회 한기대 프로그래밍 경시대회 D번문제 

    Input : two int

    Output : unmatched num

    Calculates unmatched num


    
    9/29 coded by bmkim
    
******************************************/
#include <iostream>

using namespace std;

int solution(int a, int b){
    int ret = 0;
    while(a > 1 || b > 1){
        if(a%2 != b%2)
            ret++;
        a /= 2;
        b /= 2;
    }
    if(a%2 != b%2)
        ret++;
    return ret;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        int a, b;

        cin >> a >> b;
        cout << solution(a , b) << endl;
    }
}