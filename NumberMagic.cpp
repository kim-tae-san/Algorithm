#include <iostream>
#include <string>
using namespace std;

class NumberMagicEasy{
    public:
    char check(int X[], int number){
        for(int x=0; x<8 ; x++){
            if(X[x] == number)
                return 'Y';
        }
        return 'N';
    }
    int theNumbers(string answer){
        int A[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        int B[8] = {1, 2, 3, 4, 9, 10, 11, 12};
        int C[8] = {1, 2, 5, 6, 9, 10, 13, 14};
        int D[8] = {1, 3, 5, 7, 9, 11, 13, 15};
        
        for(int i=1; i<17; i++){
            if(check(A, i) != answer[0]) continue;
            if(check(B, i) != answer[1]) continue;
            if(check(C, i) != answer[2]) continue;
            if(check(D, i) != answer[3]) continue; 
            return i;
        }
    }
};

int main(){
    NumberMagicEasy nme;
    cout << nme.theNumbers("YNYY");
}