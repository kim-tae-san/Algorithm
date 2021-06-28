#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
class IntersetingDigits{
  public:
  vector <int> divisor(int n){
      vector <int> div;
      for(int i=2; i<n;i++){
          if(n%i == 0){
              div.push_back(i);
          }
      }
      return div;
  }
  vector <int> digits(int base){
      vector <bool> num;
      vector <int> result;
      for(int i=0; i<base; i++){
          num.push_back(true);
      }
      
      for(int i=0; i<base; i++){
          for(int j=0; j<base; j++){
              for(int k=0; k<base; k++){
                  vector <int> temp = divisor(i * pow(base, 2) + j * base + k);
                  int total = i + j + k;
                  for(auto m: temp){
                      if(total% m != 0 && m < base){
                          num[m] = false;
                      }
                  }
              }
          }
      }
      for(int i=2; i<base; i++){
          if(num[i] == true){
              result.push_back(i);
          }
      }
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