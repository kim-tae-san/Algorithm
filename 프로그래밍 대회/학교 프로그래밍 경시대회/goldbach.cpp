/****************************************
    
    Gold Bach's conjecture

    Input : int n

    Output : combination of prime number

    Simulate Gold Bach's conjecture using Sieve of Eratosthenes


    9/26 coded by bmkim
    
******************************************/
#include <iostream>
#include <vector>

using namespace std;

int elatos[1000001];
vector<int> prime;

void Prime(){
    for(int i=2; i<=1000000; i++){
        elatos[i] = i;
    }
    for(int i=2; i<=1000000; i++){
        if(elatos[i] == 0)
            continue;
        for(int j = i + i; j <= 1000000; j += i){
            if(elatos[j] == 0) continue;
            elatos[j] = 0;
        }
    }
    for(int i=2; i<=1000000; i++){
        if(elatos[i] != 0) prime.push_back(i);
    }
}

int solution(int n){
    int ret = 0;
    int start = 0, last = prime.size()-1;
    while(last >= start){
        if(prime[last] + prime[start] < n){
            start++;
        }
        else if(prime[last] + prime[start] > n)
            last--;
        else{
            ret++;
            last--;
        }
    }
    return ret;
}

int main(){
    int c;
    cin >> c;
    Prime();
    while(c--){
        int n;
        cin >> n;
        cout << solution(n) << endl;
    }
}