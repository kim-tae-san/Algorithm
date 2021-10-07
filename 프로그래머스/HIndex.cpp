/****************************************
    
    Programmers Lv.2 H-Index

    Input : vector<int>

    Output : H-Index

    Calculates H-Index using sort


    
    10/7 coded by bmkim
    
******************************************/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end());
    for(int i=0; i<n; i++){
        if(citations[i] >= n - i)
            return n - i;
    }
    return 0;
}