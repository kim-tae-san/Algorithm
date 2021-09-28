/****************************************
    
    제 6회 한기대 프로그래밍 경시대회 C번 문제

    Input : Point(x, y)

    Output : IsItTriangle?

    Determine that the given point set make triangle.


    
    9/28 coded by bmkim
    
******************************************/

#include <iostream>

using namespace std;

pair<int, int> triangle[3];

bool solution(){
    long long ay = triangle[0].first - triangle[1].first;
    long long ax = triangle[0].second - triangle[1].second;
    long long by = triangle[1].first - triangle[2].first;
    long long bx = triangle[1].second - triangle[2].second;
    if(ay * bx != ax * by) return true;
    return false;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        for(int i=0; i<3; i++){
            int a, b;
            cin >> a >> b;
            triangle[i].first = a;
            triangle[i].second = b;
        }
        if(solution()){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}