#include <iostream>
#include <string>
using namespace std;
class NumberMagic2{
    public:
    int theNumber(string answer){
        int ret = 0;
        int n = 8;
        for(int i=0; i<4; i++){
            if(answer[i] == 'N'){
                ret += n;
            }
            n /= 2;
        }
        return ret + 1;
    }
};
int main(){
    NumberMagic2 nm;
    cout << nm.theNumber("NNNN");
}