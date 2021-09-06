/****************************************
    
    Two pointer algorithm

    Input : Permutation array

    Output : number of Combinations

    Calculates number of Combinations using Two pointer


    
    9/6 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> per;
int Solution(){
    if(per.size()<3)
        return 0;
    int middle = 1, end=per.size()-1;
    int ret = 0;
    int prev[2] = {per[0]-1, per[middle]-1};
    int sum = per[0] + per[middle] + per[end];
    for(int i=0; i<per.size(); i++){
        if(prev[0] == per[i])
            continue;
        middle = i + 1;
        end = per.size() - 1;
        prev[0] = per[i];
        prev[1] = per[middle] - 1;
        while(middle < end){
            sum = per[i] + per[middle] + per[end];
            if(sum == 0){
                if(prev[1] != per[middle]){
                    ret++;
                    prev[1] = per[middle];
                }
                middle++;
            }
            else if(sum > 0)
                end--;
            else
                middle++;
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
    }
    sort(per.begin(), per.end());
    cout << Solution() << endl;
}
