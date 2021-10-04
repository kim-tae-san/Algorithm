/****************************************
    
    제 8회 한기대 프로그래밍 대회 I번 문제

    Input : String and Target String

    Output : locate of Target String and Number of Target String

    Find the Target String in a String using KMP algorithm.


    
    10/4 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPartialMatch(const string & s){
    int begin = 1, length = 0;
    int n = s.size();
    vector<int> pm(n, 0);
    while(begin + length < n){
        if(s[begin+length] == s[length]){
            length++;
            pm[begin + length - 1] = length;
        }
        else{
            if(length == 0)
                begin++;
            else{
                begin += length - pm[length - 1];
                length = pm[length - 1];
            }
        }
    }
    return pm;
}

pair<int ,vector<int> > kmpsearch(const string &s, const string & obj){
    vector<int> pm = getPartialMatch(obj);
    int n = s.size();
    int m = obj.size();
    int begin = 0, matched = 0;
    pair<int, vector<int> > ret;
    ret.first = 0;
    while(n - m >= begin){
        if(matched < m && s[begin + matched] == obj[matched]){
            matched++;
            if(matched == m){
                ret.second.push_back(begin);
                ret.first++;
            }
        }
        else{
            if(matched == 0)
                begin++;
            else{
                begin += matched - pm[matched - 1];
                matched = pm[matched - 1];
            }
        }
    }
    return ret;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        string s, obj;
        cin >> s >> obj;
        pair<int, vector<int> > ret = kmpsearch(s, obj);
        cout << ret.first << endl;
        if(ret.first){
            for(auto i:ret.second)
                cout << i + 1 << " ";
            cout << endl;
        }
    }
}