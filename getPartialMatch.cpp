/***********************************
    
    KMP algorithm

    Input : pattern

    Output : suffix, preffix length array

    Calculates suffix preffix length in pattern


    
    8/21 coded by bmkim
    
***********************************/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> getPartialMatch(string& s){
    int k = s.size();
    vector<int> ret(k, 0);
    int begin = 1, length = 0;
    while(begin < k){
        if(s[begin] == s[length]){
            length++;
            ret[begin] = length;
            begin++;
        }
        else{
            if(length == 0){
                begin++;
            }
            else{
                length = ret[length-1];
            }
        }
    }
    return ret;
}
vector<int> getPrefixSuffix(string& s){
    vector<int> part = getPartialMatch(s);
    vector<int> ret;
    int length = s.size();
    while(length > 0){
        ret.push_back(length);
        length = part[length-1];
    }
    return ret;
}
int main(){
    string a,b;
    cin >> a >> b;
    a += b;
    vector<int> ret = getPrefixSuffix(a);
    int n = ret.size() - 1;
    while(n >= 0){
        cout << ret[n] << " ";
        n--;
    }
}