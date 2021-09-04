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

vector<int> kmpsearch(const string &s, const string & obj){
    vector<int> pm = getPartialMatch(obj);
    int n = s.size();
    int m = obj.size();
    int begin = 0, matched = 0;
    vector<int> ret;
    while(n - m >= begin){
        if(matched < m && s[begin + matched] == obj[matched]){
            matched++;
            if(matched == m)
                ret.push_back(begin);
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

int shifts(const string & original, const string & target){
    return kmpsearch(original + original, target)[0];
}

int main(){
    int C;
    cin >> C;
    while(C--){
        int N;
        vector<string> states;
        string current;
        int ret = 0;
        int cnt = 0;
        cin >> N >> current;
        while(N--){
            string state;
            cin >> state;
            states.push_back(state);
        }
        for(auto arg:states){
            if(cnt % 2 == 0){
                ret += shifts(arg, current);
            }
            else{
                ret += shifts(current, arg);
            }
            current = arg;
            cnt++;
        }
        cout << ret << endl;
    }
}