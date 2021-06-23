#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Cryptography{
    public:
            long long encrypt(vector <int> numbers){
            long long result = 0;
            for(int i=0; i<numbers.size();i++){
                long long temp = 1;
                numbers[i]++;
                for(int j=0; j<numbers.size();j++){
                    temp *= numbers[j];
                }
                numbers[i]--;
                result = max(result, temp);
            }
            return result;
        }
};

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector <int> numbers = {1000, 999, 998, 997, 996, 995};
    Cryptography crypt;
    long long result = crypt.encrypt(numbers);
    printf("%lld", result);
}