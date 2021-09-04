#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Cryptography2{
    public:
        long long encrypt(vector <int> numbers){
            long long result = 1;
            int minindex = min_element(numbers.begin(), numbers.end()) - numbers.begin();
            numbers[minindex]++;
            for(int i=0; i<numbers.size(); i++){
                result *= numbers[i];
            }
            return result;
        }
};

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector <int> numbers = {1000, 999, 998, 997, 996, 995};
    Cryptography2 crypt;
    long long result = crypt.encrypt(numbers);
    printf("%lld", result);
}