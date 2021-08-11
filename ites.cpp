#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int K, N, C, n1=1983;
    cin >> C;
    while(C--){
        cin >> K >> N;
        long long start = n1;
        int ret = 0;
        while(N--){
            long long num = 0;
            start = (start * 214013 + 2531011) % (long long)pow(2, 32);
            start = start % 10000 + 1;
            long long saved = start;
            num += start;
            while(K >= num){
                if(num == K){
                    ret++;
                    break;
                }
                saved = (saved * 214013 + 2531011) % (long long)pow(2, 32);
                saved = saved % 10000 + 1;
                num += saved;
            }
        }
        cout << ret << endl;
    }
}