#include <iostream>

using namespace std;

int money[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
int ret[8] = {0,};

void solution(int n){
    for(int i=0; i<8; i++){
        ret[i] = n / money[i];
        n %= money[i]; 
    }
}

int main(){
    int c;
    cin >> c;
    while(c--){
        int a, b;
        cin >> a >> b;
        solution(b-a);
        for(auto i:ret){
            cout << i << " ";
        }
        cout << endl;
    }
}