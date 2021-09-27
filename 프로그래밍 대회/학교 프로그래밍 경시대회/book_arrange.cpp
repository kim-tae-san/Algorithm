/****************************************
    
    제 6회 한기대 프로그래밍 경시대회 B번 문제

    Input : BookInfo(pair<double, string>)

    Output : arranged Book(sort)

    Sort the given booklist


    
    9/27 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<pair<double, string> > booklist;

void solution(){
    sort(booklist.begin(), booklist.end());
}

int main(){
    int c;
    cin >> c;
    while(c--){
        booklist = vector<pair<double, string> >();
        int returned;
        cin >> returned;
        while(returned--){
            double bun;
            string jeo;
            cin >> bun >> jeo;
            booklist.push_back(make_pair(bun, jeo));
        }
        int currentbook;
        cin >> currentbook;
        while(currentbook--){
            double bun;
            string jeo;
            cin >> bun >> jeo;
            booklist.push_back(make_pair(bun, jeo));
        }
        solution();
        for(auto i:booklist){
            cout << i.first << " " <<  i.second << endl;
        }
    }
}