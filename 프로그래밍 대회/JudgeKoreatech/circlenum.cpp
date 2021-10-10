/****************************************
    
    Judge Koreatech 1008

    Input : int n1, n2

    Output : repeating decimal

    Explain repeating decimal


    
    10/10 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solution(int n1, int n2){
    cout << n1 / n2 << '.';
    n1 %= n2;
    if(n1 == 0){
        cout << "(0)" << endl;
        return;
    }
    vector<int> qv;
    vector<int> rv;
    vector<int> cir;
    map<pair<int, int> , int> hashmap;
    int start = 0, end = 0, n = 1;
    while(true){
        n1 *= 10;
        int r = n1 % n2;
        int q = n1 / n2;
        pair<int, int> qr = make_pair(q, r);
        n1 = r;
        if(r == 0){
            qv.push_back(q);
            qv.push_back(0);
            start = qv.size()-1;
            end = qv.size()-1;
            break;
        }
        else if(hashmap[qr] > 0){
            start = hashmap[qr] - 1;
            pair<int, int> temp = make_pair(qv[qv.size()-1], rv[rv.size()-1]);
            end = hashmap[temp] - 1;
            break;
        }
        hashmap[qr] = n;
        qv.push_back(q);
        rv.push_back(r);
        n++;
    }
    for(int i=0; i< start; i++){
        cout << qv[i];
    }
    cout << "(";
    for(int i=start; i<=end; i++){
        cout << qv[i];
    }
    cout << ")" << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        int n1, n2;
        cin >> n1 >> n2; 
        solution(n1, n2);
    }
}