/****************************************
    
    online algorithm

    Input : test case, signal length, object number

    Output : result number

    Calculates number frequency with queue


    
    8/14 coded by bmkim
    
******************************************/
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
class randnum{
    private:
    long seed = 1983;
    public:
    int randn(){
        int out = seed % 10000 + 1;
        seed = (seed * 214013 + 2531011) % (long)pow(2, 32);
        return out;
    }
};
int main(){
    int K, N, C;
    cin >> C;
    while(C--){
        cin >> K >> N;
        queue<int> q;
        randnum r;
        q.push(1983);
        int sum = 1983;
        int ret = 0;
        while(N--){
            int nextnum = r.randn();
            while(K <= sum && !q.empty()){
                if(K == sum)
                    ret++;
                sum -= q.front();
                q.pop();
            }
            sum += nextnum;
            q.push(nextnum);
        }
        cout << ret << endl;
    }
}