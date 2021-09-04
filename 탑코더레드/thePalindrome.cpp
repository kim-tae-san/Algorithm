#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class ThePalindrome{
    public:
    int find(string s){
        int result = 999;
        int before = 999;               // 이전 결과값을 저장하는 변수
        int cnt = 0;
        bool where = true;              // 주어진 문자열에서 회문이 중앙에 있는지 검사용
        for(int i=0; i<s.size();i++){
            vector <char> stack;
            bool flag = true;           // pop과정을 마치고 다시 pop과정으로 돌아왔는지 확인하는 변수
            bool flag2 = false;         // pop과정을 마치고 push과정이 생겼는지 확인하는 변수
            for(int j=0; j<s.size(); j++){
                if(i!=j){
                    if(stack.empty()){
                        if(flag2)
                            flag = false;
                        stack.push_back(s[j]);
                    }
                    else{
                        if(stack.back() == s[j] && flag)
                        {
                            flag2 = true;
                            stack.pop_back();
                        }
                        else{
                            if(flag2)
                                flag = false;
                            stack.push_back(s[j]);
                        }
                    }
                }
            }
            result = min(result, (int)stack.size());
            if(result==before && result < s.size() -1)          // 이전 결과값과 현재 결과값 같으면 카운터 증가
                cnt++;
            before = result;
        }
        if(cnt + 1 == s.size())         // 카운터값이 문자열길이와 같을때(어떤것을 제거해도 회문의 길이가 같다면 가장 긴 회문이 중앙이 아닌것)
            result++;
        result += s.size();
        return result;
    }
};
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    ThePalindrome palindrome;
    int a = palindrome.find("abdfhdyrbdbsdfghjkllkjhgfds");
    cout << a;
}