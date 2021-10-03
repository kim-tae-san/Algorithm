/****************************************
    
    제 8회 한기대 프로그래밍 대회 G번 문제

    Input : Hash Map of visited student

    Output : when they visited

    HashMap Problem


    
    10/3 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> visited;
unordered_map<int, vector<int> > ret;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i =1; i<=n; i++){
        int std;
        cin >> std;
        ret[std].push_back(i);
    }
    cin >> n;
    for(int i =0; i< n; i++){
        int std;
        cin >> std;
        if(ret[std].size() > 0){
            for(auto x:ret[std])
                cout << x << " ";
        }
        else{
            cout << -1 << " ";
        }
        cout << endl;
    }
}