/****************************************
    
    DFS algorithm

    Input : start point, count

    Output : number of Combinations

    Calculates number of Combinations using DFS


    
    9/4 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
vector<int> per;
vector<int> v;
vector<bool> visited;
int Solution(int cnt, int start){
    int ret = 0;
    if(v.size()>0)
        if(v[0] > 0)
            return 0;
    if(cnt == 3){
        int n = 0;
        for(auto i:v)
            n += i;
        if(n == 0)
            return 1;
        return 0;
    }
    int before = INT_MIN;
    for(int i=start; i<per.size(); i++){
        if(!visited[i] && before != per[i]){
            v.push_back(per[i]);
            visited[i] = true;
            before = per[i];
            ret += Solution(cnt + 1, i);
            before = per[i];
            visited[i] = false;
            v.pop_back();
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    while(n--){
        int temp;
        cin >> temp;
        per.push_back(temp);
        visited.push_back(false);
    }
    sort(per.begin(), per.end());
    cout << Solution(0, 0);
}
