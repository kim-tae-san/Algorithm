#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
class IntersetingDigits{
  public:
  vector <int> divisor(int n){
      vector <int> div;
      for(int i=2; i<=n;i++){
          if(n%i == 0){
              div.push_back(i);
          }
      }
      return div;
  }
  vector <int> digits(int base){
      vector <int> result;
      result = divisor(base - 1);
      return result;
  }  
};
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    IntersetingDigits digits;
    vector <int> result = digits.digits(26);

    for(auto i:result){
        printf("%d ", i);
    }
}