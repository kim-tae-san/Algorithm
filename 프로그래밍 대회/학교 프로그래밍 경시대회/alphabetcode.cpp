/****************************************
    
    제 6회 한기대 프로그래밍 경시대회 I번 문제

    Input : string set and target string

    Output : guessed num

    Guess the target string's num using Permutation
    
    9/30 coded by bmkim
    
******************************************/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<pair<string, int> > wookyeong;
unordered_map<char, int> hashmap;

bool isok(){
    for(auto i:wookyeong){
        int isok = 0;
        for(auto j:i.first){
            isok += hashmap[j];
        }
        if(isok != i.second)
            return false;
    }
    return true;
}

int solution(string target){
    vector<int> perm = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    do{
        unordered_map<char, int>::iterator it;
        int itr = 0;
        for(it = hashmap.begin(); it!= hashmap.end(); it++){
            it->second = perm[itr];
            itr++;
        }
        if(isok())
            break;
    }while(next_permutation(perm.begin(), perm.end()));
    int ret = 0;
    for(auto i:target){
        ret += hashmap[i];
    }
    return ret;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        hashmap.clear();
        wookyeong = vector<pair<string, int> >();
        int n;
        cin >> n;
        while(n--){
            int num;
            string s;
            cin >> s >> num;
            wookyeong.push_back(make_pair(s, num));
            for(auto i:s){
                hashmap[i] = 1;
            }
        }
        string target;
        cin >> target;
        for(auto i: target)
            hashmap[i] = 1;
        cout << solution(target) << endl;
    } 
}