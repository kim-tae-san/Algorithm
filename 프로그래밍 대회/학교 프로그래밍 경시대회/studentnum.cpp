#include <iostream>
using namespace std;
int main(){
    int c; 
    cin >> c;
    while(c--){
        string a;
        cin >> a;
        string num = a.substr(2,2);
        printf("%02d\n", stoi(num));
    }
}