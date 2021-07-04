#include <string>
#include <iostream>

using namespace std;

class Palindrome2
{
    public:
    int size(string s){
        // 답의 문자 길이를 결정합니다.
        for(int i=s.size(); ;i++){
            bool flag = true;
            for(int j=0; j<s.size();j++){
                // 반대쪽에 문자가 존재하는 데 다를 경우 플래그를 변경합니다.
                if((i-j-1)<s.size()&&s[j]!=s[i-j-1]){
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }
    }
};
int main(){
    Palindrome2 pal;
    int a = pal.size("abacaba");
    cout << a;
}