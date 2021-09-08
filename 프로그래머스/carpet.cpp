/****************************************
    
    Brute Force

    Input : Number of colors

    Output : A Width and Height of Rectangle

    Calculates Width and Height using Brute Force


    
    9/8 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1; i<=yellow; i++){
        if(yellow % i != 0)
            continue;
        int width = yellow / i;
        int height = i;
        if((height+2)*2 + (width+2)*2 - 4 == brown){
            answer.push_back(width+2);
            answer.push_back(height+2);
            break;
        }
    }
    return answer;
}
int main(){
    int brown, yellow;
    cin >> brown >> yellow;
    vector<int> ret = solution(brown, yellow);
    for(auto i:ret)
        cout << i << endl;
}