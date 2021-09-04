#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    int C;
    cin >> C;

    const string opening("({["), closing(")}]");

    while(C--){
        stack<char> bracket;
        string a;
        cin >> a;
        string temp = "NO";
        for(auto i:a){
            if(opening.find(i) != -1){
                bracket.push(i);
            }
            else{
                if(bracket.empty()){
                    bracket.push(i);
                    break;
                }
                int flag = opening.find(bracket.top());
                if(flag != closing.find(i)){
                    bracket.push(i);
                    break;
                }
                bracket.pop();
            }
        }
        if(bracket.empty())
            temp = "YES";
        cout << temp << endl;
    }
}