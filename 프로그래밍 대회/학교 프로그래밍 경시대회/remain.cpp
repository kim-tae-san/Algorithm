#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int a, b, ret;
        cin >> a >> b;
        if(a>=0){
            ret = a % b;
        }
        else{
            if(abs(a)%b == 0){
                ret = 0;
            }
            else{
                ret = b - abs(a) % b;
            }
        }
        cout << ret << endl;
    }
}