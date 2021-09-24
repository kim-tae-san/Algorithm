#include <iostream>

using namespace std;

int solution(int p, int k){
    int n = p;
    while(true){
        int ret = n / 3 + 3 * (n / k);
        if(ret == p)
            return n;
        if(ret > p * k)
            return -1;
        n++;
    }
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