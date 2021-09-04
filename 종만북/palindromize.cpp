/****************************************
    
    KMP algorithm

    Input : string

    Output : Min Palindrome length

    Makes Palindrome by using KMP algorithm

    8/23 coded by bmkim
    
****************************************/
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
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
int palindromize(string &rev){
    string s = rev;
    reverse(rev.begin(), rev.end());
    vector<int> gpm = getPartialMatch(rev);
    int begin = 0, matched = 0;
    int n = s.size();
    while(begin < n){
        if(matched < n && s[begin+matched] == rev[matched]){
            matched++;
            if(begin + matched == n)
                return matched + begin * 2;
        }
        else{
            if(matched == 0)
                begin++;
            else{
                begin += matched - gpm[matched-1];
                matched = gpm[matched-1];
            }
        }
    }
    return 0;
}
int main(){
    int C;
    cin >> C;
    while(C--){
        string s;
        cin >> s;
        cout << palindromize(s) << endl;
    }
}